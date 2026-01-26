#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// DEFINIÇÕES DO DISPLAY LCD I2C
#define ENDERECO_LCD 0x27   // Endereços comuns: 0x27 ou 0x3F
#define COLUNAS 16
#define LINHAS 2
// DEFINIÇÃO DO PINO DO SENSOR
#define PINO_SENSOR 7      // Pino digital conectado à saída do SW-520D
// CRIAÇÃO DO OBJETO DO DISPLAY
LiquidCrystal_I2C lcd(ENDERECO_LCD, COLUNAS, LINHAS);
void setup() {
    // Inicializa a comunicação serial (opcional para testes)
Serial.begin(9600);
// Configura o pino do sensor como entrada digital
  pinMode(PINO_SENSOR, INPUT);
  // Inicializa o display LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  // Mensagem inicial
  lcd.setCursor(0, 0);
  lcd.print("Sensor SW-520D");
  lcd.setCursor(0, 1);
  lcd.print("Inicializando");
  delay(3000);
}
void loop() {
  // Lê o estado do sensor de inclinação
int estadoSensor = digitalRead(PINO_SENSOR); // Limpa o display para atualizar a informação
  lcd.clear();
  // Texto fixo na primeira linha
  lcd.setCursor(0, 0);
  lcd.print("Inclinado?");
  // Verifica o estado do sensor
lcd.setCursor(0, 1);
if (estadoSensor == HIGH) {
    lcd.print("SIM");
    Serial.println("Inclinado: SIM");
  }
else
  {
    lcd.print("NAO");
    Serial.println("Inclinado: NAO");
}
  // Intervalo entre leituras
  delay(1000);
  }

