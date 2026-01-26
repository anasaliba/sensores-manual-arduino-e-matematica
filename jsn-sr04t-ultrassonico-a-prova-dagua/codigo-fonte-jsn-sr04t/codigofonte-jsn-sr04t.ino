#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Definição dos pinos do sensor ultrassônico
#define PINO_ECHO 11   // Pino que recebe o sinal refletido (ECHO)
#define PINO_TRIG 12   // Pino que emite o pulso ultrassônico (TRIG)
// Definições do display LCD I2C
#define ENDERECO_LCD 0x27   // Endereços comuns: 0x27 ou 0x3F
#define COLUNAS 16
#define LINHAS  2
// Variáveis para cálculo da distância
long tempo; // Armazena o tempo de ida e volta da onda
,→ ultrassônica
int distancia; // Armazena a distância calculada em centímetros
// Criação do objeto do display LCD
LiquidCrystal_I2C lcd(ENDERECO_LCD, COLUNAS, LINHAS);
void setup() {
// Inicializa a comunicação com o display LCD lcd.init();
lcd.backlight();
lcd.clear();
// Configuração dos pinos do sensor ultrassônico
pinMode(PINO_TRIG, OUTPUT); // Pino responsável por disparar o pulso
,→ ultrassônico
pinMode(PINO_ECHO, INPUT); // Pino responsável por receber o eco do
,→ pulso
  // Inicializa a comunicação serial (opcional, para depuração)
  Serial.begin(9600);
}
void loop() {
// Garante que o pino TRIG inicie em nível baixo digitalWrite(PINO_TRIG, LOW); delayMicroseconds(4);
  // Emite o pulso ultrassônico
  digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIG, LOW);
  // Mede o tempo em que o pino ECHO permanece em nível alto
  tempo = pulseIn(PINO_ECHO, HIGH);
// Cálculo da distância em centímetros
// Velocidade do som 0,034 cm/ţs
// Divide-se por 2 pois o tempo corresponde ao trajeto de ida e volta distancia = (tempo * 0.034) / 2;

  // Exibe a distância no display LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distancia (cm)");
  lcd.setCursor(0, 1);
  lcd.print(distancia);
  // Pequeno atraso entre as leituras
  delay(1000);
}