#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Definição dos pinos do sensor ultrassônico HC-SR04
#define PINO_TRIGGER 12   // Pino responsável por emitir o pulso
,→ ultrassônico
#define PINO_ECHO 13 // Pino responsável por receber o eco do pulso
// Definições do display LCD I2C
#define ENDERECO_LCD 0x27   // Endereços comuns: 0x27 ou 0x3F
#define COLUNAS 16
#define LINHAS  2
// Variáveis para o cálculo da distância
long tempo; // Armazena o tempo de ida e volta da onda
,→ ultrassônica
float distancia; // Armazena a distância calculada em centímetros
// Criação do objeto do display LCD
LiquidCrystal_I2C lcd(ENDERECO_LCD, COLUNAS, LINHAS);
void setup() {
  // Inicializa a comunicação serial (opcional, para depuração)
  Serial.begin(9600);
  // Configura os pinos do sensor ultrassônico
  pinMode(PINO_TRIGGER, OUTPUT);
  pinMode(PINO_ECHO, INPUT);
  // Inicializa o display LCD
  lcd.init();
  lcd.backlight();
    lcd.clear();
  // Mensagem inicial exibida durante a inicialização
  lcd.setCursor(0, 0);
  lcd.print("HC-SR04 Ativo");
  lcd.setCursor(0, 1);
  lcd.print("Inicializando");
  delay(3000);
  lcd.clear();
}
void loop() {
  // Garante que o pino TRIGGER inicie em nível baixo
  digitalWrite(PINO_TRIGGER, LOW);
  delayMicroseconds(5);
  // Emite o pulso ultrassônico
  digitalWrite(PINO_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIGGER, LOW);
  // Mede o tempo em que o pino ECHO permanece em nível alto
  tempo = pulseIn(PINO_ECHO, HIGH);
// Cálculo da distância em centímetros
// A constante 58 resulta da velocidade do som no ar
// e do fato de o pulso percorrer o caminho de ida e volta distancia = tempo / 58.0;
  // Exibe o valor da distância no display LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distancia (cm)");
lcd.setCursor(0, 1);
lcd.print(distancia, 1); // Exibe a distância com uma casa decimal
  // Envia o valor também para o monitor serial
  Serial.print("Distancia = ");
  Serial.print(distancia);
  Serial.println(" cm");
  // Atraso entre as medições
delay(500);
}