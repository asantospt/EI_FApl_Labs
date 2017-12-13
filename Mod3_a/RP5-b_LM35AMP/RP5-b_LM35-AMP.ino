/**
 * @ex - Mod.3a - RP5-a
 * @brief - ler tempª pelo LM35 e usando um AMPOP
 * @date - 29/11; 06/12
 * @author - Afonso & Natanael
 * @state - TESTAR; Calcs. corretos, mas mostra valores errados
 *          INC
 */

/** 
 * LIGAÇÕES: @Arduino 'Mega 2560'
 * 5V -> USB
 * GND -> breadboard 
 * A0 -> saída do AMP-OP
 * 
 * @LM35
 * 1 -> Vs/5V
 * 2 -> V_out, AMPOP, Pin 3
 * 3 -> GND
 * 
 * @Amplificador Operacional 'AD8032'
 * 1 -> OUT1/V1, Arduino/Pin A1
 * 2 -> -IN1, RA (R. 9.1 kOhm) + (2) + R. 1 kOhm
 * 3 -> +IN1, V_out LM35 
 * 4 -> -Vs/GND
 * 8 -> +Vs/5V
 */

 const int PIN_AMP = A0;
 const int PIN_LED = 10;
 const int GANHO_AMP = 10 ;//10 - pois Ganho = r1-9100 + r2-1000 / r2-1000
 const int DELTA_T1 = 5000;
 unsigned long tRef1= 0; //valor de referencia para contagem dos 5 segundos
 
 void setup() {
   Serial.begin(9600);
   pinMode( PIN_LED , OUTPUT);
 }
 
 void loop() {
   float temp = 0.0;
   float voltage = 0.0;
   float vLm35 = 0.00;
   float instanteAtual = millis();
   
   int sensorValue = analogRead(PIN_AMP);
 
   voltage = (5.0 / 1023) * sensorValue; //Com Ganho Operacional
   
   vLm35 = voltage / GANHO_AMP; //Sem Ganho Operacional
   
   temp = vLm35 / 0.01;
 
   // MOSTRAR A TEMPª A CADA 5 SEGS.
   if ( (instanteAtual - tRef1) >= DELTA_T1 ){
     
     Serial.print("Temperatura: "); 
     Serial.println(temp);
     tRef1 = instanteAtual;
      
     }
 
   if (temp >= 24.00){
     
     digitalWrite( PIN_LED , HIGH); 
     delay(100);//dar tempo para acender o led
     
     }else{
       
       digitalWrite(PIN_LED, LOW);
       delay(100);//dar tempo para apagar o led
       
       } 
   }