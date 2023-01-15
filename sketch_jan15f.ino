#include "LiquidCrystal_I2C.h"
#include "MPU6050.h"
LiquidCrystal_I2C lcd(0x27 , 20 , 4);
MPU6050 mpu;
float timeStep = 0.01;
void setup() {
  Serial.begin(9600);
  mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
  lcd.init();
  lcd.backlight();
}

void loop() {
   Vector normAccel = mpu.readNormalizeAccel();
  int pitch = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis * normAccel.YAxis + normAccel.ZAxis * normAccel.ZAxis)) * 180.0) / M_PI;
  int roll = (atan2(normAccel.YAxis, normAccel.ZAxis) * 180.0) / M_PI;

  // Output raw
  lcd.setCursor(0,0);
  lcd.print("Pitch = ");
  lcd.setCursor(8,0);
  lcd.print(pitch);
  lcd.setCursor(0,1);
  lcd.print("Roll = ");
  lcd.setCursor(8,1);
  lcd.print(roll);  
  lcd.setCursor(0,2);
  lcd.print("X = ");
  lcd.print(analogRead(A0));
  lcd.print("  ");
  lcd.setCursor(0,3);
  lcd.print("Y = ");
  lcd.print(analogRead(A1));
  lcd.print("  ");
  lcd.setCursor(4,3);
  
  
}
