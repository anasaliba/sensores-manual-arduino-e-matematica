// INCLUSÃO DE BIBLIOTECAS
#include "mpu6050.h" // Biblioteca para controle do sensor
,→ MPU-6050
#include <Wire.h> // Comunicação I2C
#include <LiquidCrystal_I2C.h> // Controle do display LCD via I2C
// DEFINIÇÕES DO DISPLAY LCD
#define endereco  0x27  // Endereço I2C do display (valores comuns: 0x27
,→ ou 0x3F)
#define colunas 16 #define linhas 2
// INSTANCIAÇÃO DO DISPLAY LCD
LiquidCrystal_I2C lcd(endereco, colunas, linhas); void setup() {
Serial.begin(9600); // Inicializa a comunicação serial para depuração // Inicialização do sensor MPU-6050
  mpu_begin();
  // Inicialização do display LCD
lcd.init();
lcd.backlight();
lcd.clear();
// Inicia a comunicação com o display
// Liga a iluminação de fundo
// Limpa qualquer informação anterior
// Mensagem de calibração
lcd.print("Calibrando...");
delay(1000);
// Realiza a calibração do sensor
// O valor indica a quantidade de leituras usadas no cálculo mpu_calibrate(200);
// Confirmação visual da calibração
lcd.setCursor(0, 1);
lcd.print("Calibrado!");
// Reinicia os acumuladores internos do sensor
mpu_reset();
delay(1000);
lcd.clear();

// Mensagem inicial antes das medições
  lcd.print("- Vamos medir! -");
  delay(5000);
}
void loop() {
// Atualiza os dados do sensor (leitura do acelerômetro e giroscópio) mpu_loop();
  lcd.clear();
  lcd.print("Angulo (graus)");
// Exibe no display o ângulo no eixo Z (yaw)
// Os valores dos eixos X e Y foram omitidos por não serem utilizados lcd.setCursor(0, 1);
lcd.print(getAngleZ());
delay(1000); // Intervalo entre as leituras }