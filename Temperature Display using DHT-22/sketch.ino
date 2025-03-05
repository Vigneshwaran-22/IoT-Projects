#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 to your LCD I2C address

void setup() {
  lcd.begin();
  dht.begin();
  lcd.print("Temp:");
}

void loop() {
  float temp = dht.readTemperature();
  lcd.setCursor(6, 0);
  lcd.print(temp);
  lcd.print(" C");
  delay(2000);
}
