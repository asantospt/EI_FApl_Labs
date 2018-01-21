/* 
* @file LCD.ino
* @brief Imprimir tempª lida num LCD
* @date 31/12
* @author afonso
* @state TESTAR
*/

/* 
* LIGAÇÕES: -> Arduino 'Uno'
* 5 V -> USB
* GND -> breadboard
* Pin 10 -> Res. 1 kOhm + (LCD/ CS) + Res. 2 kOhm      // Mega, 53 (SS)
* Pin 11 -> Res. 1 kOhm + (LCD/ MOSI) + Res. 2 kOhm    // Mega- 51
* Pin 12 -> LCD/ MISO                                  // Mega- 50
* Pin 13 -> Res. 1 kOhm + (LCD/ SCK) + Res. 2 kOhm     // Mega- 52
* Pin 0 -> Res. 1 kOhm + (LCD/ DC/RS) + Res. 2 kOhm    // Mega- 49
* 
* -> LCD TFT a cores
* VCC -> 3.3 V
* GND -> 0 V
* CS -> Res. 2 kOhm + (CS) + Res. 1 kOhm + Arduino/ Pin 10
* DC/RS -> Res. 2 kOhm + (DC/RS) + Res. 1 kOhm + Arduino/ Pin 0
* MOSI -> Res. 2 kOhm + (MOSI) + Res. 1 kOhm + Arduino/ Pin 11
* MISO -> Arduino/ Pin 12
* SCK -> Res. 2 kOhm + (SCK) + Res. 1 kOhm + Arduino/ Pin 13
* LED -> Res. 10 kOhm + VCC
* RESET -> VCC
*/

// Incluir as bibliotecas necessárias
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h> // 2 bibls. necessárias p/ LCD
#include <SPI.h>              // protocolo de comunicação usado

// Definir os terminais de DC e CS
#define TFT_DC 0
#define TFT_CS 10

// Criar um objeto tft com indicacao dos terminais DC e CS
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

const int INPUT_PIN = A0;
float voltage = 0.0, voltage_old = 0.0;

void setup() {
  // inicializar o tft
  tft.begin();
  
  // colocar fundo a branco
  tft.fillScreen(ILI9341_WHITE);
  
  // definir orientaçcao da escrita
  tft.setRotation(2);

  tft.setCursor(0, 0);          // coluna, linha
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLUE);
  tft.setTextSize(2);
  tft.println("Fisica Aplicada");
  tft.setTextColor(ILI9341_BLACK);
  tft.setTextSize(3);
  tft.print("Ano: ");
  tft.println("2017-18");
  
  tft.setCursor(0, 50);
  tft.setTextColor(ILI9341_YELLOW, ILI9341_RED);
  tft.setTextSize(3);
  tft.println("Valor lido: ");
  
  Serial.begin (9600);
}

void loop() {
  voltage = analogRead(INPUT_PIN) * (5.0 / 1023);
  
  tft.setCursor(0, 75);
  tft.setTextColor(ILI9341_WHITE);
  tft.print(voltage_old);
  
  Serial.println(voltage);
  
  tft.setCursor(0, 75);
  tft.setTextColor(ILI9341_BLACK);
  tft.print(voltage);
  
  voltage_old = voltage;
  
  delay(500);
}

