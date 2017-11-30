/**
 * @ex - Mod.3a - RP3-c
 * @brief - ler valor do NTC (com expr. da P4)
 * @date - 29/11
 * @author - Afonso & Natanael
 * @state - OK
 */

/** 
 * LIGAÇÕES: -> Arduino 'Mega 2560'
 * 5V -> USB
 * GND -> breadboard 
 *      A0 -> LDR
 *    ? -> R. 2700 Ohm

 */

const int PIN_NTC = A0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(PIN_NTC);
  
  float voltage = sensorValue * (5.0 / 1023.0);

  float RES_NTC = 0.0;
  RES_NTC = 2700 * ((5.0 / voltage) - 1);
  //TODO:
  //Serial.print("Res. da NTC = ");     
  Serial.println(RES_NTC);        // Valor da resistência da NTC
}
