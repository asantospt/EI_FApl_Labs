/**
 * @ex - Mod.3b - RP3-c
 * @brief - Servo + Buzzer
 * @date - 06/12
 * @author - Afonso & Natanael
 * @state - OK

* LIGAÇÕES: --> Arduino 'Mega 2560'
* 5V -> USB
* GND -> breadboard
* Pin 9 -> Servo, Laranja (Sinal)
* 
* @Servo
* Laranja (Sinal) -> Arduino, Pin 9
* Vermelho (+) -> VCC
* Castanho (-) -> GND
* 
* @Buzzer 
* + -> Arduino, Pin 9 + R. 10 kOhm
* - -> GND
*/

#include <Servo.h>

Servo myservo;  
const int PIN_SERVO = 9; 
const int MAX_ANG_SERVO = 170;
const int MIN_ANG_SERVO = 10; 
const int PIN_BUZZER = 8;
int pos = 0;   

void setup() {
  Serial.begin (9600);
  myservo.attach(PIN_SERVO);  
  pinMode(PIN_BUZZER, OUTPUT);
}

void loop() {
  for (pos = MIN_ANG_SERVO; pos <= MAX_ANG_SERVO; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    Serial.println(pos); 
    delay(15);                      

    if (pos == MAX_ANG_SERVO) {
      tone(PIN_BUZZER, 880, 1000);
      delay(1000);
      noTone(PIN_BUZZER);                    
      delay(500);    
    }
  }
  for (pos = MAX_ANG_SERVO; pos >= MIN_ANG_SERVO; pos -= 1) { 
    myservo.write(pos);             
    Serial.println(pos); 
    delay(15);                     
  
    if (pos == MIN_ANG_SERVO) {
      tone(PIN_BUZZER, 440, 1000);
      delay(1000);    
    }
  }
}
