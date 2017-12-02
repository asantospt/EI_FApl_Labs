/**
 * @ex - Mod.3b - RP2-b
 * @brief - 
 * @date - 02/12
 * @author - Afonso & Natanael
 * @state - inc
 */

/*
HC-SR04 distance sensor example
Conections:
VCC to arduino 5V
GND to arduino GND
Trig to Arduino pin 3
Echo to Arduino pin 4
*/

const int trigPin = 3;
const int echoPin = 4;

void setup() {
  Serial.begin (9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
}

void loop() {
  long duration;
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  Serial.print(duration); //
  Serial.println(" microssegundos");
  delay(1000);
}


