/**
 * @ex - Mod.3a - RP5-a
 * @brief - ler tempª pelo LM35, usando 1 ADC
 * @date - 29/11
 * @author - Afonso & Natanael
 * @state - inc
 */

/** 
 * LIGAÇÕES: @Arduino 'Mega 2560'
 * 5V -> USB
 * GND -> breadboard 
 * A0 -> LM35
 * ? -> R. 22K
 * 
 * @LM35
 * 1 -> Vs/5V
 * 2 -> V_out, Arduino/Pin A0
 * 3 -> GND
 * 
 * @Amplificador Operacional 'AD8032'
 * 1 -> OUT1/V1, Arduino/Pin A0
 * 2 -> -IN1, RA + (2) + R. 1 kOhm
 * 3 -> +IN1, V_out LM35 
 * 4 -> -Vs/GND
 * 8 -> +Vs/5V
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
