/**
 * @ex - Mod.3a - RP4-b
 * @brief - ler valor do NTC
 * @date - 29/11
 * @author - Afonso & Natanael
 * @state - OK
 */

/** 
 * LIGAÇÕES: -> Arduino 'Mega 2560'
 * 5V -> USB
 * GND -> breadboard 
 * A0 -> NTC
 * ? -> R. 2.7K
 */

const int PIN_NTC = A0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Leitura do Vout do NTC (V_NTC)
  int sensorValue = analogRead(PIN_NTC);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);

  // voltagem do NTC. Ao aquecer o sensor, V0 vai aumentando
  Serial.println(voltage);      
  delay(500);
}

