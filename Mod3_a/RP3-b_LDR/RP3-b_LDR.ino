/**
 * @ex - Mod.3a - RP3-b
 * @brief - ler luminosidade com 1 LDR
 * @date - 29/11
 * @author - Afonso & Natanael
 * @state - OK
 */

/** 
 * LIGAÇÕES: --Arduino 'Mega 2560'
 * 5V -> USB
 * GND -> breadboard 
 * A0 -> LDR + (A0) + R. 22 kOhm
 * 
 * --LDR
 * + -> 5V
 * - -> Vout, Arduino/Pin A0
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // print out the value you read:
  Serial.println(voltage);
}
