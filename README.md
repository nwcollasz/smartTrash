# ♻️ Lixeira Inteligente para Identificação de Metais 🤖

Protótipo desenvolvido com Arduino Uno para identificar objetos metálicos e automatizar a abertura de uma lixeira.

## Componentes:
- Arduino Uno
- Sensor indutivo NPN
- Servo motor
- LEDs vermelho e verde
- Resistores, protoboard e jumpers

## Funcionamento:
1. 🔴 **Standby:** tampa fechada.
2. 📡 **Detecção:** sensor identifica a presença de metal.
3. 🟢 **Abertura:** servo motor abre a tampa automaticamente.
4. ⏱️ **Fechamento:** após 5 segundos, a tampa fecha.

## Conexões:

| Componente | Pino |
|---|---|
| Sensor indutivo | 2 |
| Servo motor | 9 |
| LED vermelho | 4 |
| LED verde | 5 |

## Como executar:
1. Abra `smarttrash.ino` na Arduino IDE.
2. Conecte o Arduino Uno ao computador.
3. Selecione a placa e a porta corretas.
4. Clique em **Upload**.

## Fotos reais do projeto
<img width="504" height="304" alt="unnamed" src="https://github.com/user-attachments/assets/716cd27f-89f8-49d4-8e1c-79cb6d69b1bd" />

<img width="304" height="304" alt="unnamed" src="https://github.com/user-attachments/assets/a78e8fcb-916c-472c-bbe7-2afd29c569d8" />

https://github.com/user-attachments/assets/e14675c4-87ca-4c1a-bfbf-88ae7a9a3185


