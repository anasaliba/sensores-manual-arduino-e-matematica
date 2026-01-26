#include <Wire.h>
#include <LIDARLite.h> #include <LiquidCrystal_I2C.h>
// Definições do display LCD I2C
#define ENDERECO_LCD 0x27
#define COLUNAS 16
#define LINHAS 2
// Criação dos objetos do sensor e do display
LIDARLite lidar;
LiquidCrystal_I2C lcd(ENDERECO_LCD, COLUNAS, LINHAS);
void setup() {
  // Inicializa a comunicação serial (opcional para depuração)
  Serial.begin(115200);
// Inicializa o sensor LIDAR com configuração padrão // e comunicação I2C em modo rápido (400 kHz) lidar.begin(0, true);
lidar.configure(0);
  // Inicializa o display LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  // Mensagem inicial exibida no display
  lcd.setCursor(0, 0);
  lcd.print("Vamos medir!");
  delay(5000);
}
void loop() {
  // Limpa o display antes de cada leitura
  lcd.clear();

  // Exibe o texto informativo
  lcd.setCursor(0, 0);
  lcd.print("Distancia (cm)");
  // Realiza a leitura com correção de viés
int distancia = lidar.distance();
  // Exibe o valor da distância no display
  lcd.setCursor(0, 1);
  lcd.print(distancia);
  // Pequeno atraso entre as medições
  delay(1000);
// Leituras adicionais sem correção de viés,
// utilizadas para aumentar a estabilidade do sensor for (int i = 0; i < 99; i++)
{
    lidar.distance(false);
  }
}
