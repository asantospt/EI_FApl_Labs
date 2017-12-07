/**
 * @ex - Mod.3a - RP5-a
 * @brief - ler tempª pelo LM35 e usando um AMPOP
 * @date - 29/11; 06/12
 * @author - Afonso & Natanael
 * @state - TESTAR; Calcs. corretos, mas mostra valores errados
 *          INC
 */

/** 
 * LIGAÇÕES: @Arduino 'Mega 2560'
 * 5V -> USB
 * GND -> breadboard 
 * A0 -> saída do AMP-OP
 * 
 * @LM35
 * 1 -> Vs/5V
 * 2 -> V_out, AMPOP, Pin 3
 * 3 -> GND
 * 
 * @Amplificador Operacional 'AD8032'
 * 1 -> OUT1/V1, Arduino/Pin A1
 * 2 -> -IN1, RA (R. 9.1 kOhm) + (2) + R. 1 kOhm
 * 3 -> +IN1, V_out LM35 
 * 4 -> -Vs/GND
 * 8 -> +Vs/5V
 */

const int PIN_AMP = A0;
const int GANHO_AMP = 10;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp = 0.0;
  float voltage = 0.0;
  
  int sensorValue = analogRead(PIN_AMP);

  voltage = (5.0 / 1023) * sensorValue;

  // MOSTRAR A TEMPª
  temp = voltage * GANHO_AMP;
  Serial.print("Temperatura: "); 
  Serial.println(temp);
  delay(1000);
  
  // MOSTRAR A TEMPª A CADA 5 SEGS.
  // TODO: 
}