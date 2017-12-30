/* 
* @file LCD.ino
* @brief Imprimir tempª lida num LCD
* @date 30/12
* @author afonso
* @state TESTAR
*/

/* 
* LIGAÇÕES: -> Arduino 'Mega 2560'
* 5V -> USB
* GND -> breadboard
* Pin 49 -> LCD/DC
* Pin 50 -> LCD/MISO
* Pin 51 -> LCD/MOSI
* Pin 52 -> LCD/SCLK
* Pin 53 -> LCD/CS
* 
* -> LCD TFT a cores
* VCC -> 3.3V
* GND -> 0V
* CS -> Arduino/Pin 53
* RESET -> 3.3V
* DC -> Arduino/Pin 49
* MOSI -> Arduino/Pin 51
* SCLK -> Arduino/Pin 52
* LED -> Res. 10 kOm + VCC
* MISO -> Arduino/Pin 50
*/

// Incluir as bibliotecas necessárias
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h> // 2 bibls. necessárias p/ LCD
#include <SPI.h>              // protocolo de comunicação usado

// Definir os terminais de DC e CS
#define TFT_DC 49
#define TFT_CS 53

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

