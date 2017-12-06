/**
 * @ex - Mod.3b - RP2-b
 * @brief - Registe o tempo entre a emissão e a receção do feixe ultrassonoro
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
  delay(1000);

  // Largura de 1 folha A4: aprox. 600 microssegundos
}

