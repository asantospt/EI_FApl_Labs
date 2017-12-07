/**
 * @ex 
 * @brief - ligar Buzzer
 * @date - 06/12
 * @author - Afonso & Natanael
 * @state - OK
 */

/** @Buzzer 
* + -> Pin 8 (Arduino) + R. 10 kOhm
* - -> GND (Arduino) 
*/

const int PIN_BUZZER = 8;
const int FREQ_BUZZER = 880;

void setup() {
  pinMode(PIN_BUZZER, OUTPUT);
}

void loop() {
  // tone(terminal, frequência, duração)
  tone(PIN_BUZZER, FREQ_BUZZER, 2000);
  delay(2000);
  
  noTone(PIN_BUZZER);                    
  delay(1000);
}