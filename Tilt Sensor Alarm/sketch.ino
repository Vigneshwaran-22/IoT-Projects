#include <Arduino.h>

const int tiltSensorPin = 4; // GPIO pin connected to the tilt switch
const int buzzerPin = 13; // GPIO pin connected to the buzzer

void setup() {
  pinMode(tiltSensorPin, INPUT_PULLUP); // Set tilt switch pin as input with pull-up resistor
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  Serial.begin(115200);
}

void loop() {
  int sensorValue = digitalRead(tiltSensorPin);
  
  if (sensorValue == HIGH) {
    // Tilt detected, turn on buzzer
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Tilt detected! Buzzer ON.");
  } else {
    // No tilt, turn off buzzer
    digitalWrite(buzzerPin, LOW);
    Serial.println("No tilt detected. Buzzer OFF.");
  }
  
  delay(100); // Short delay to avoid rapid changes
}
