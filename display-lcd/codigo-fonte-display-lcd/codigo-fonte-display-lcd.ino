#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Definições do display LCD I2C
#define ENDERECO_LCD 0x27   // Endereços comuns: 0x27 ou 0x3F
#define COLUNAS 16
#define LINHAS  2
// Criação do objeto do display LCD
LiquidCrystal_I2C lcd(ENDERECO_LCD, COLUNAS, LINHAS);
void setup() {
// Inicializa a comunicação com o display lcd.init();
lcd.backlight();
lcd.clear();
// Mensagem exibida apenas uma vez durante a inicialização
lcd.setCursor(0, 0);
  lcd.print("Ola, Mundo!");
  lcd.setCursor(0, 1);
  lcd.print("Inicializando...");
  delay(5000);
  // Demonstração do controle da iluminação do display
  lcd.noBacklight();
  delay(2000);
  lcd.backlight();
  delay(2000);
  // Limpa o display ao final do setup
  lcd.clear();
}
void loop() {
// Exibe uma mensagem fixa no display durante a execução contínua lcd.setCursor(0, 0);
lcd.print("LCD Funcionando");
  lcd.setCursor(0, 1);
  lcd.print("Teste OK");
  delay(1000);
}