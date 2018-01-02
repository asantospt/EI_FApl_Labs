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
* Pin 10 -> LCD/ CS      // Mega, 53 (SS)
* Pin 11 -> LCD/ MOSI    // Mega- 51
* Pin 12 -> LCD/ MISO    // Mega- 50
* Pin 13 -> LCD/ SCK     // Mega- 52
* Pin 0 -> LCD/ DC/RS    // Mega- 49
* 
* -> LCD TFT a cores
* VCC -> 3.3 V
* GND -> 0 V
* CS -> Arduino/ Pin 10
* DC/RS -> Arduino/ Pin 0
* MOSI -> Arduino/ Pin 11
* MISO -> Arduino/ Pin 12
* SCK -> Arduino/ Pin 13
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

