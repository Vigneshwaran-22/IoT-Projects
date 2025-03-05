#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define POT_PIN A0
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 to your LCD I2C address

void setup() {
  lcd.begin();
  lcd.print("Voltmeter");
}

void loop() {
  int sensorValue = analogRead(POT_PIN);
  float voltage = sensorValue * (5.0 / 1023.0);
  
  lcd.setCursor(0, 1);
  lcd.print("Voltage: ");
  lcd.print(voltage);
  lcd.print(" V");

  delay(500);
}
