/**
 * @ex - Mod.3a - P5
 * @brief - Escrever alterações p/ mostrar a dist. p/ o objeto
 * @date - 05/12
 * @author - Afonso & Natanael
 * @state - ok
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
  
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  
  duration = pulseIn(PIN_ECHO, HIGH);
  Serial.print(duration); 
  Serial.println(" microssegundos");

  /** ALTERAÇÕES: 
   * Sabendo o tempo que demora o som a ir até ao objeto e voltar ao sensor (usando a função'pulseIn'), conseguimos 
   *      calcular a distância a que se encontra esse objeto. 
   * Usamos no cálculo a Vel. de propagação dos Ultrassons no Ar e uma simplificação da fórmula: 
   * 2d = DeltaT(zero) * Vel.Ultrassons
   */

   // Solução - Afonso
  float distance = (((float)duration * (float)VEL_ULTRASSONS_AR) / 2.0) / 10000.0;  

  //2 Soluções - Natanael
  //float distance = ((float)duration / 58.31);
  //float distance = ((float)duration * 0,0172);

  // Imprimir a distância no monitor Série
  Serial.print(distance); 
  Serial.println(" cm");
  delay(1000);
}
