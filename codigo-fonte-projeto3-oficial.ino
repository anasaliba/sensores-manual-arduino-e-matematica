#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <LIDARLite.h>
#include <LiquidCrystal_I2C.h>

Adafruit_MPU6050 mpu;
LIDARLite lidar;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  Serial.begin(115200);
  Wire.begin();

  // -------- LIDAR --------
  lidar.begin(0, true);
  lidar.configure(0);

  // -------- MPU6050 --------
  if (!mpu.begin()) {
    Serial.println("MPU6050 nao encontrado!");
    while (1);
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  // -------- LCD --------
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Projeto 3");
  lcd.setCursor(0, 1);
  lcd.print("Inicializando");
  delay(2000);
}

void loop() {

  // ---------- LIDAR ----------
  float distancia_cm = lidar.distance();
  for (int i = 0; i < 5; i++) {
    lidar.distance(false);
  }

  // ---------- MPU6050 ----------
  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  // Ângulo em graus
  float angulo_graus = atan2(accel.acceleration.y,
                             accel.acceleration.z) * 180.0 / PI;

  // Conversão para radianos
  float angulo_rad = angulo_graus * PI / 180.0;

  // ---------- CÁLCULOS TRIGONOMÉTRICOS ----------
  float altura_cm = distancia_cm * sin(angulo_rad);
  float base_cm   = distancia_cm * cos(angulo_rad);

  // ---------- LCD ----------
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("H:");
  lcd.print(altura_cm, 1);
  lcd.print("cm");

  lcd.setCursor(0, 1);
  lcd.print("B:");
  lcd.print(base_cm, 1);
  lcd.print("cm");

  // ---------- SERIAL ----------
  Serial.print("Distancia (cm): ");
  Serial.print(distancia_cm);
  Serial.print(" | Angulo (graus): ");
  Serial.print(angulo_graus);
  Serial.print(" | Altura (cm): ");
  Serial.print(altura_cm);
  Serial.print(" | Base (cm): ");
  Serial.println(base_cm);

  delay(500);
}
