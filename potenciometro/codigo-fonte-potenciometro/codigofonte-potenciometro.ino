#include "Adafruit_VL53L0X.h"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// DEFINIÇÕES
#define endereco  0x27 // Endereços comuns: 0x27, 0x3F
#define colunas   16
#define linhas    2

Adafruit_VL53L0X lox = Adafruit_VL53L0X();
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

float distancia = 0.0;

void setup() {
  Serial.begin(9600);

  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test.");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power
  Serial.println(F("VL53L0X API Continuous Ranging example\n\n"));

  // start continuous ranging
  lox.startRangeContinuous();

  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear(); // LIMPA O DISPLAY

  lcd.print("- Vamos medir! -");
  delay(5000); // DELAY DE 5 SEGUNDOS 
}

void loop() {
  if (lox.isRangeComplete()) {
    lcd.clear();
    lcd.print("Distancia (cm)");
    distancia = (float)lox.readRange() / 10;
    lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
    lcd.print(distancia);
    // Serial.print("Distance in mm: ");
    // Serial.println(lox.readRange());
    delay(1000);
  }
}