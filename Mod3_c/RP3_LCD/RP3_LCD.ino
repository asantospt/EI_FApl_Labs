/**
 * @ex - Mod.3c - RP3
 * @brief - 
 * @date - 
 * @author - Afonso & Natanael
 * @state - inc / test
 */

/*
* Exemplo básico de escrita para o LCD
*
* As ligações do LCD são as seguintes:
* VCC -> 3.3V
* GND -> 0V
* CS -> Arduino 53
* RESET -> 3.3V
* DC -> Arduino 49
* MOSI -> Arduino 51
* SCLK -> Arduino 52
* LED -> Resistencia de 10k ligada a VCC
* MISO -> Arduino 50
*/

// incluir as bibliotecas necessárias
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// definir os terminais de DC e CS
#define TFT_DC 49
#define TFT_CS 53

// criar um objeto tft com indicacao dos terminais DC e CS
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

const int inPin = A1;
float voltage=0., voltage_old=0.;

void setup() {
  // inicializar o tft
  tft.begin();
  
  // colocar fundo a branco
  tft.fillScreen(ILI9341_WHITE);
  
  // definir orientaçcao da escrita
  tft.setRotation(2);
  
  tft.setCursor(0, 0); // coluna, linha
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLUE);
  tft.setTextSize(2);
  tft.println("Fisica Aplicada");
  tft.setTextColor(ILI9341_BLACK);
  tft.setTextSize(3);
  tft.print("Ano: ");
  tft.println("2017_18");
  
  tft.setCursor(0, 50);
  tft.setTextColor(ILI9341_YELLOW, ILI9341_RED);
  tft.setTextSize(3);
  tft.println("Valor lido:");
  
  Serial.begin (9600);
}

void loop() {
  voltage = analogRead(inPin)*(5.0/1023);
  
  tft.setCursor(0, 75);
  tft.setTextColor(ILI9341_WHITE);
  tft.print(voltage_old);
  
  Serial.println(voltage);
  
  tft.setCursor(0, 75);
  tft.setTextColor(ILI9341_BLACK);
  tft.print(voltage);
  
  voltage_old=voltage;
  delay(1000);
}

