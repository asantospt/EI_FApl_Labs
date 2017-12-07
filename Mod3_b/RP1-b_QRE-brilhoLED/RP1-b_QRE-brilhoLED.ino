/**
 * @ex - Mod.3b - RP1-b
 * @brief - ativar % do brilho do LED mediante o V_out do QRE
 *       https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/
 * @date - 06/12
 * @author - Afonso & Natanael
 * @state - OK
 */

/** 
 * LIGAÇÕES: @Arduino 'Mega 2560'
 * 5V -> USB
 * GND -> breadboard 
 * A0 -> sensor QRE1113, Pin 3
 * 
 * @Sensor de reflexão/proximidade 'QRE1113'
 * 1 -> 5V + R1 (130 kOhm)
 * 2 -> GND
 * 3 -> V_out + R2 (10 kOhm) 
 * 4 -> GND
 */

const int PIN_QRE = A0;
const int PIN_LED_VERD = 5;

void setup() {
  pinMode(PIN_LED_VERD, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(PIN_QRE);
  float voltage = sensorValue * (5.0 / 1023.0);
  
  Serial.println(voltage);

  // 20% do brilho max. do LED
  if (voltage < 2.50) {
    // analogWrite(PIN_LED_VERD, 255 * 0.2); 
    analogWrite(PIN_LED_VERD, 51);
    delay(500);   
  } else {
    // 100% do brilho max. do LED
    analogWrite(PIN_LED_VERD, 255);
    delay(500);
  }  
}


