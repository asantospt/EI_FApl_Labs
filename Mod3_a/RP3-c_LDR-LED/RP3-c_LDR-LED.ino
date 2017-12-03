/**
 * @ex - Mod.3a - RP3-c
 * @brief - ler luminosidade com 1 LDR; atuar 1 LED
 * @date - 29/11
 * @author - Afonso & Natanael
 * @state - OK
 */

/** 
 * LIGAÇÕES: --Arduino 'Mega 2560'
 * 5V -> USB
 * GND -> breadboard 
 * A0 -> LDR + (A0) + R. 22 kOhm
 * (Pin 13 -> LED_BUILTIN)
 * 
 * --LDR
 * + -> 5V
 * - -> V_out, Arduino/Pin A0
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
  //Serial.println(voltage);

  // valor max. lido (a descoberto) = 4.50
  // valor min. lido (tapado) = 2.00
  if (voltage >= 3.25) {      // valor méd. calculado
    digitalWrite(LED_BUILTIN, LOW);  
    Serial.println("MUITA LUZ!"); 
  }
  else {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("POUCA LUZ! LED ON");
  }
}
