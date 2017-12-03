/**
 * @ex - Mod.3b - RP3-c
 * @brief - Servo e Buzzer
 * @date - 03/12
 * @author - Afonso & Natanael
 * @state - inc
 */

 /* 
* LIGAÇÕES: --> Arduino 'Mega 2560'
* 5V -> USB
* GND -> breadboard
* A0 -> Sensor ultrassons
* 
* --> Servo
* --> Buzzer + R. 10 kOhm
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

const int PIN_SERVO = 9; 
const int MIN_ANG_SERVO = 10; 
const int MAX_ANG_SERVO = 170; 

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(PIN_SERVO);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

