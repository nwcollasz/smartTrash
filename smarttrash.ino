
#include <Servo.h>

Servo tampa;

// pinos:
const int PIN_SENSOR_INDU = 2;
const int PIN_SERVO = 9;
const int PIN_LED_VERMELHO = 4;
const int PIN_LED_VERDE = 5;

// o sensor detecta metal em high:
const int SENSOR_INDU_DETECTA = HIGH;

// posicoes do servo:
const int POSICAO_FECHADA = 90;
const int POSICAO_ABERTA = 0;

// tempo que a tampa fica aberta:
const unsigned long TEMPO_ABERTA = 5000;

// intervalo de leitura:
const unsigned long INTERVALO_LEITURA = 20;

// estados:
bool tampaAberta = false;
bool metalAnteriormenteDetectado = false;

unsigned long instanteAbertura = 0;
unsigned long ultimaLeitura = 0;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_SENSOR_INDU, INPUT);
  pinMode(PIN_LED_VERMELHO, OUTPUT);
  pinMode(PIN_LED_VERDE, OUTPUT);

  // estado inicial: tampa fechada:
  digitalWrite(PIN_LED_VERMELHO, HIGH);
  digitalWrite(PIN_LED_VERDE, LOW);

  tampa.attach(PIN_SERVO);
  tampa.write(POSICAO_FECHADA);

  Serial.println("Sistema iniciado!");
  Serial.println("Aguardando metal...");
}

void loop() {
  unsigned long agora = millis();

  if (agora - ultimaLeitura >= INTERVALO_LEITURA) {
    ultimaLeitura = agora;

    int estadoAtual = digitalRead(PIN_SENSOR_INDU);

    bool metalDetectado =
        (estadoAtual == SENSOR_INDU_DETECTA);

    // detecta a chegada do metal:
    if (metalDetectado && !metalAnteriormenteDetectado) {
      Serial.println("METAL DETECTADO!");

      if (!tampaAberta) {
        tampa.write(POSICAO_ABERTA);
        tampaAberta = true;
        instanteAbertura = agora;

        // verde ligado enquanto a tampa esta aberta:
        digitalWrite(PIN_LED_VERDE, HIGH);
        digitalWrite(PIN_LED_VERMELHO, LOW);

        Serial.println("Tampa aberta - LED verde ligado.");
      }
    }

    metalAnteriormenteDetectado = metalDetectado;
  }

  // fecha a tampa apos 5 segundos:
  if (tampaAberta &&
      agora - instanteAbertura >= TEMPO_ABERTA) {

    tampa.write(POSICAO_FECHADA);
    tampaAberta = false;

    // vermelho ligado quando a tampa fecha:
    digitalWrite(PIN_LED_VERDE, LOW);
    digitalWrite(PIN_LED_VERMELHO, HIGH);

    Serial.println("Tampa fechada - LED vermelho ligado.");
  }
}
