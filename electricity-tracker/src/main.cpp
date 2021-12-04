/*
  Copyright (c) 2021 Jakub Mandula
  Example of using one pzemA module with Software Serial interface.
  ================================================================
  If only RX and TX pins are passed to the constructor, software
  serial interface will be used for communication with the module.
*/

// #include "./pzem/PzemReader.h"
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

// #if !defined(PZEM_A_RX_PIN) && !defined(PZEM_A_TX_PIN) && !defined(PZEM_B_RX_PIN) && !defined(PZEM_B_TX_PIN) && !defined(PZEM_C_RX_PIN) && !defined(PZEM_C_TX_PIN)
// #define PZEM_A_RX_PIN D1
// #define PZEM_A_TX_PIN D2
// #define PZEM_B_RX_PIN D3
// #define PZEM_B_TX_PIN D4
// #define PZEM_C_RX_PIN D5
// #define PZEM_C_TX_PIN D6
// #endif

// PzemReader pzemReaderFase1("Fase1", D1, D2);
// PzemReader pzemReaderFase2("Fase2", D3, D4);
// PzemReader pzemReaderFase3("Fase3", D5, D6);

U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C u8g2(U8G2_R0, /* clock=*/D9, /* data=*/D10, /* reset=*/U8X8_PIN_NONE); // Adafruit Feather ESP8266/32u4 Boards + FeatherWing OLED

void printLineIntoDisplay(String line, int x, int y)
{
  char lineChar[20];
  line.toCharArray(lineChar, 20);
  u8g2.setFontDirection(0);
  u8g2.drawStr(x, y, lineChar);
}

void printTitleIntoDisplay(String title)
{
  char lineChar[20];
  title.toCharArray(lineChar, 20);
  u8g2.setFontDirection(3);
  u8g2.drawStr(0, 30, lineChar);
}

void printIntoDisplay(
    String title,
    String line1,
    String line2,
    String line3)
{
  u8g2.clearBuffer();
  printTitleIntoDisplay(title);
  printLineIntoDisplay(line1, 20, 1);
  printLineIntoDisplay(line2, 20, 10);
  printLineIntoDisplay(line3, 20, 20);
  u8g2.sendBuffer();
}

// void handlePrintIntoDisplay(PzemReadingModel model)
// {

//   u8g2.setFont(u8g2_font_6x10_tf);
//   u8g2.setFontRefHeightExtendedText();
//   u8g2.setDrawColor(1);
//   u8g2.setFontPosTop();

//   Serial.println("");
//   Serial.println("**************************");

//   Serial.println(model.title);
//   if (model.isNotValid())
//   {
//     Serial.println("Error when reading pzem values");
//   }
//   Serial.println(model.voltageFormated());
//   Serial.println(model.currentFormated());
//   Serial.println(model.powerFormated());
//   Serial.println(model.energyFormated());
//   Serial.println(model.frequencyFormated());
//   Serial.println(model.pfFormated());

//   Serial.println("**************************");
//   Serial.println("");

//   printIntoDisplay(
//       model.title,
//       model.voltageFormated(),
//       model.currentFormated(),
//       model.powerFormated());

//   delay(2500);

//   printIntoDisplay(
//       model.title,
//       model.energyFormated(),
//       model.frequencyFormated(),
//       model.pfFormated());

//   delay(2500);
// }

void setup()
{
  /* Debugging serial */
  Serial.begin(9600);

  u8g2.begin();
}

void loop()
{
  Serial.println("**************************");
  Serial.println("Debuing");
  Serial.println("**************************");
  // handlePrintIntoDisplay(pzemReaderFase1.getRead());
  // handlePrintIntoDisplay(pzemReaderFase2.getRead());
  // handlePrintIntoDisplay(pzemReaderFase3.getRead());
}