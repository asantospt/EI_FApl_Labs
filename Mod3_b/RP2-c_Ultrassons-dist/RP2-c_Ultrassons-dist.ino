/**
 * @ex - Mod.3b - RP2-c
 * @brief - Calc. distância para 1 objecto
 * @date - 06/12
 * @author - Afonso & Natanael
 * @state - OK
 */

/** 
* LIGAÇÕES: @Arduino 'Mega 2560'
* 5V -> USB
* GND -> breadboard
* A0 -> Sensor ultrassons
* 
* @Sensor ultrassons 'HC-SR04'
* VCC -> 5V
* GND -> GND 
* Trig -> Arduino, Pin 3
* Echo -> Arduino, Pin 4
*/

const int PIN_TRIG = 3;
const int PIN_ECHO = 4;
// vel. propagação dos ultrassons no ar = 343 m/s
const int VEL_ULTRASSONS_AR = 343;  

void setup() {
  Serial.begin (9600);
  
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
}

void loop() {
  long duration;
  
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  
  duration = pulseIn(PIN_ECHO, HIGH);
  Serial.print(duration); 
  Serial.println(" microssegundos");

  // Cálculo da distância em cm
  // float distance = (((float)duration * (float)VEL_ULTRASSONS_AR) / 2.0) / 10000.0;
  
  //Solução Natanael
  float distance = ((float)duration / 58.31);
  //float distance = ((float)duration * 0,0172);
  Serial.print(distance); 
  Serial.println(" cm");
  delay(1000);
}


