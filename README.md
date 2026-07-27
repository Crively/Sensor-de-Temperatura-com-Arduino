# 🌡️ Monitor de Temperatura com Arduino e Display LCD

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Arduino](https://img.shields.io/badge/Arduino-UNO-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Wokwi Simulator](https://img.shields.io/badge/Wokwi-Simulator-00B4D8?style=for-the-badge&logo=arduino&logoColor=white)
![Status](https://img.shields.io/badge/Status-Em%20Desenvolvimento-yellow?style=for-the-badge)

## 📋 Descrição do Projeto

Este projeto consiste em um sistema de monitoramento de temperatura e umidade para gestão de vacas leiteiras, utilizando um **Arduino Uno**, um **sensor DHT11** e um **display LCD I2C**. O objetivo é fornecer uma interface simples e visual para leitura das condições ambientais em tempo real. O sistema também pode ser facilmente adaptado para controlar um relé, permitindo futuras automações, como o acionamento de ventiladores ou aquecedores.

## 🎯 Funcionalidades Principais

*   **Leitura de Temperatura e Umidade:** Utiliza o sensor DHT11 para capturar os dados do ambiente.
*   **Exibição em Display LCD:** Mostra as informações de forma clara em um display LCD 16x2 com comunicação I2C.
*   **Estrutura para Atuação:** Inclui um relé no circuito, pronto para ser integrado à lógica de controle (ex: ligar um dispositivo quando a temperatura ultrapassar um limite).
*   **Simulação no Wokwi:** Projeto totalmente simulável na plataforma Wokwi, facilitando testes e ajustes.

## 🔧 Componentes Utilizados

| Componente          | Quantidade | Descrição                               |
| ------------------- | ---------- | --------------------------------------- |
| Arduino Uno         | 1          | Microcontrolador principal.             |
| Sensor DHT11        | 1          | Sensor de temperatura e umidade.        |
| Display LCD 16x2 I2C| 1          | Display para exibição dos dados.        |
| Módulo Relé         | 1          | Para controle de cargas externas.       |
| Jumpers e Protoboard| Vários     | Para montagem do circuito.              |

## 🔌 Esquema de Ligação (Pinout)

A conexão entre os componentes é a seguinte:

| Componente | Pino do Componente | Pino no Arduino Uno |
| :--------- | :----------------- | :------------------ |
| **Display LCD I2C** | GND                | GND                 |
|             | VCC                | 5V                  |
|             | SDA                | A4 (SDA)            |
|             | SCL                | A5 (SCL)            |
| **Sensor DHT11**    | VCC                | 5V                  |
|             | SDA (ou OUT)       | Pino Digital 2 (Definido no código) |
|             | NC (Não Conectado) | -                   |
|             | GND                | GND                 |
| **Módulo Relé**     | VCC                | 5V                  |
|             | GND                | GND                 |
|             | IN (Sinal)         | Pino Digital 3 (Definido no código) |

**Observações:**
*   Os pinos para o sensor DHT11 e o relé podem ser alterados no código, mas a ligação física deve corresponder.
*   O display I2C utiliza os pinos analógicos A4 e A5 para comunicação SDA e SCL, respectivamente.

## 🛠️ Como Utilizar

### 1. Simulação no Wokwi
O projeto foi desenvolvido e pode ser testado diretamente no Wokwi. Acesse o link do projeto para visualizar o circuito e executar a simulação:
[**Link para o Projeto no Wokwi**](https://wokwi.com/projects/469703273876091905)

### 2. Montagem Física
1.  Conecte todos os componentes conforme a tabela de ligação acima.
2.  Certifique-se de que as alimentações (VCC e GND) estejam corretas para evitar danos.
3.  Conecte o Arduino Uno ao computador via cabo USB.

### 3. Configuração do Software
1.  Instale a **IDE do Arduino** ou utilize o **Editor Web do Arduino**.
2.  Instale as bibliotecas necessárias:
    *   `DHT sensor library` (por Adafruit)
    *   `LiquidCrystal I2C` (por Frank de Brabander)
3.  Carregue o código (sketch) no Arduino.

## 🚀 Possíveis Melhorias Futuras

*   [ ] **Controle do Relé:** Implementar lógica para ligar/desligar o relé com base em limites de temperatura ou umidade.
*   [ ] **Registro de Dados:** Adicionar um módulo SD para registrar as leituras ao longo do tempo.
*   [ ] **Comunicação Serial:** Enviar os dados para o computador via porta serial para análise ou gráficos.
*   [ ] **Ajuste de Contraste:** Adicionar um potenciômetro para ajustar o contraste do display
*   [ ] **Interface Web:** Utilizar um módulo ESP8266 para enviar os dados para a nuvem.

## 🤝 Contribuição

Sinta-se à vontade para fazer um *fork* deste projeto, sugerir melhorias ou relatar problemas. Toda contribuição é bem-vinda!

1.  Faça um *Fork* do projeto.
2.  Crie uma nova *branch* (`git checkout -b feature/nova-feature`).
3.  Faça o *commit* das suas alterações (`git commit -m 'Adiciona nova feature'`).
4.  Faça o *Push* para a *branch* (`git push origin feature/nova-feature`).
5.  Abra um *Pull Request*.

---
