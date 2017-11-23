/**
 * @ex - Mod.3a - RP3-c
 * @brief - ler luminosidade com 1 LDR; atuar 1 LED
 * @date -
 * @author - 
 * @state - TESTAR
 */

/** 
 * LIGAÇÕES: -> Arduino 'Mega 2560'
 * 5V -> USB
 * GND -> breadboard 
 * A0 -> LDR
 * ? -> R. 22K
 * Pin 13 -> LED interno
 */

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);

  Serial.println(voltage);


  // TODO ligar LED qd luminosidade < valor médio
  
}
