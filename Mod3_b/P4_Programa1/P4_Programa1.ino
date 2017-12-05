/**
 * @ex - Mod.3a - P4
 * @brief - comentar o cod. do Prog. 1
 * @date - 03/12
 * @author - Afonso & Natanael
 * @state - ok
 */

// declaração de constantes, usadas no programa
const int trigPin = 3;
const int echoPin = 4;

// função executada apenas 1x, quando Arduino é ligado à alimentação
void setup() {
  // define a velocidade da transmissão de dados da ligação Série
  Serial.begin (9600);
  
  // define o tipo de Pin, INPUT ou OUTPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // coloca o Pin off
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
}

// função executada sem parar, enquanto o Arduino tiver alimentação. É aqui que se colocam as instruções
void loop() {
  // declaração de 1 var. do tipo 'long'
  long duration;
  
  // coloca o Pin on
  digitalWrite(trigPin, HIGH);
  // espera durante 10 microssegundos
  delayMicroseconds(10);
  // coloca o Pin off
  digitalWrite(trigPin, LOW);
  
  // lê o pulso do Pin. Lê quanto tempo está a HIGH
  duration = pulseIn(echoPin, HIGH);
  
  // imprime na porta Série o valor da var.
  Serial.print(duration); 

  // imprime na porta Série a string
  Serial.println(" microssegundos");
  // espera durante 1 segundo
  delay(1000);
}
