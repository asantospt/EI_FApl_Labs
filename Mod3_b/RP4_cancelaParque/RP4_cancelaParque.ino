/**
 * @ex - Mod.3b - RP4
 * @brief - Controlo da cancela de um parque de estacionamento
 * @date - 09/12
 * @author - Afonso & Natanael
 * @state - INC
 */

/** 
 * LIGAÇÕES: @Arduino 'Mega 2560'
 * 5V -> USB
 * GND -> breadboard
 * A0 -> sensor QRE1113, Pin 3/V_out
 * Pin 2 -> LED verde
 * Pin 3 -> Sensor ultrassons, Trig
 * Pin 4 -> Sensor ultrassons, Echo
 * Pin 5 -> Buzzer
 * Pin 6 -> Servo, Laranja (Sinal)
 * 
 * @Sensor de reflexão/proximidade 'QRE1113'
 * 1 -> 5V + R1 (130 kOhm)
 * 2 -> GND
 * 3 -> V_out + R2 (10 kOhm) 
 * 4 -> GND
 *
 * @LED verde
 * + -> Arduino, Pin 2 + R. __ kOhm
 * - -> GND
 *
 * @Sensor ultrassons 'HC-SR04'
 * VCC -> 5V
 * GND -> GND 
 * Trig -> Arduino, Pin 3
 * Echo -> Arduino, Pin 4
 *
 * @Servomotor
 * Laranja (Sinal) -> Arduino, Pin 6
 * Vermelho (+) -> VCC
 * Castanho (-) -> GND
 * 
 * @Buzzer 
 * + -> Arduino, Pin 5 + R. 10 kOhm
 * - -> GND
 *
 */

// Bibliotecas extra usadas 
#include <Servo.h>
  
Servo myservo;  
const int PIN_QRE = A0;
const int PIN_LED = 2;
const int PIN_UL_TRIG = 3;
const int PIN_UL_ECHO = 4;
const int PIN_BUZZER = 5;
const int PIN_SERVO = 6; 
const int MAX_ANG_SERVO = 170;
const int MIN_ANG_SERVO = 5; 
int pos = 0;  

// Valores pré-definidos no enunciado
const float PERC_BRILHO_LED = 25.5;
const float QRE_DETECAO = 990.0;         // TODO: test leituras.   Valor médio de quando 1 veículo é detetado
const int ALTURA_MAX_VEIC = 30;          // distância do sensor ao topo do veículo
const int GRAUS_CANCELA_FECHADA = 5;
const int GRAUS_CANCELA_ABERTA = 95;
const int FREQ_BUZZER = 440;

// Declaração de funções
float lerProximidade();

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  myservo.attach(PIN_SERVO);  
  Serial.begin (9600);
}

void loop() {
  /* TODO: funções p/ cada funcionalidade:
   1- acender LED
   2- ler proximidade veículo
   3- ler distância ao topo do veículo
   4- controlar cancela
   5- Buzzer
  */

  Serial.println("inicio LOOP...");



  Serial.println("fim LOOP...");
}

/**
 * @descr 
 * @params 
 * @return 
 */
void atuarLED() {  
  // Quando não é detetado nenhum veículo > LED c/ 10% do brilho 
  if (voltage < 2.50) { 
    analogWrite(PIN_LED_VERD, PERC_BRILHO_LED);
    delay(500);   
  } else {
    // Veículo detetado > LED c/ 100% do brilho  
    analogWrite(PIN_LED_VERD, 255);
    delay(500);
  }
}

/**
 * @descr Verificar se existe veículo perto da cancela, com sensor de reflexão/proximidade 'QRE1113'
 * @params {nada}
 * @return valor lido; Sem deteção: [995-1001]; Tot. tapado: 33
 */
float lerProximidade() {  
  float valorQRE = 0.0;
  float voltage = 0.0;

  valorQRE = analogRead(PIN_QRE);
  Serial.print("valor QRE = ");
  Serial.println(valorQRE);

  voltage = valorQRE * (5.0 / 1023.0);
  Serial.print("voltage QRE = ");
  Serial.println(voltage);

  return voltage;
}

/**
 * @descr 
 * @params 
 * @return 
 */
void lerDistanciaVeiculo() {  
  
}

/**
 * @descr 
 * @params 
 * @return 
 */
void controlarCancela() {  
  
  // abrir cancela

  // fechar cancela
}

/**
 * @descr 
 * @params 
 * @return 
 */
void atuarBuzzer() {  
  // ligar buzzer
  tone(PIN_BUZZER, FREQ_BUZZER, 1000);
  
  // desligar buzzer
  noTone(PIN_BUZZER);                    
  delay(1000);
}


