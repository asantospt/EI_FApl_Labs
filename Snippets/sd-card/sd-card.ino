/** 
 * @file sd-card.ino
 * @brief Gravar / Ler do cartão memória
 * @date 30/12
 * @author afonso
 * @state INC
 */

#include <SPI.h>
#include <SD.h>

// definir o terminal CS
#define SD_CS=47;

// criar um objeto File para criação/acesso a ficheiros
File myFile;

void setup() {
  Serial.begin (9600);
  
  // Inicializar cartão SD
  if (!SD.begin(SD_CS)) {
    Serial.println(”Erro no acesso SD!!");
  }
  else{
    Serial.println(”SD inicializado..”);
    myFile = SD.open(”FApl.TXT", FILE_WRITE);
  }
  
}

void loop() {



}
