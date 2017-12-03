/**
 * @ex - Mod.3b - RP1-a
 * @brief - ler V_out do QRE
 * @date - 
 * @author - Afonso & Natanael
 * @state - testar
 */

/** 
 * LIGAÇÕES: @Arduino 'Mega 2560'
 * 5V -> USB
 * GND -> breadboard 
 * A0 -> sensor QRE1113
 * 
 * @Sensor de reflexão/proximidade 'QRE1113'
 * 1 -> 5V + R1
 * 2 -> GND
 * 3 -> V_out
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
 
}


