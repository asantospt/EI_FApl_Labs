/**
 * @ex - Mod.3a - RP5-a
 * @brief - ler tempª pelo LM35, usando 1 ADC
 * @date - 29/11
 * @author - Afonso & Natanael
 * @state - inc
 */

/** 
 * LIGAÇÕES: -> Arduino 'Mega 2560'
 * 5V -> USB
 * GND -> breadboard 
 *    A0 -> LM35
 *    ? -> R. 22K
 */

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);

  float voltage = sensorValue * (5.0 / 1023.0);
  
  // print out the value you read:
  Serial.println(voltage);
}
