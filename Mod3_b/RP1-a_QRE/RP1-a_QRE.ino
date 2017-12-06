/**
 * @ex - Mod.3b - RP1-a
 * @brief - ler V_out do QRE
 * @date - 06/12
 * @author - Afonso & Natanael
 * @state - OK
 */

/** 
 * LIGAÇÕES: @Arduino 'Mega 2560'
 * 5V -> USB
 * GND -> breadboard 
 * A0 -> sensor QRE1113
 * 
 * @Sensor de reflexão/proximidade 'QRE1113'
 * 1 -> 5V + R1 (130 kOhm)
 * 2 -> GND
 * 3 -> V_out + R2 (10 kOhm) 
 * 4 -> GND
 */

const int PIN_QRE = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(PIN_QRE);

  float voltage = sensorValue * (5.0 / 1023.0);
  
  Serial.println(voltage);
  delay(500);

  /** Valores Lidos:
   *  min: 0.19  (com deteção em cima)
   *  max: 5.00  (sem deteção)
   */
}
