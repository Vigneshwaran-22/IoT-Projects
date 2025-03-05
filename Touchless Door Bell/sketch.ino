// Pin Definitions
const int irSensorPin = 2; // Digital pin connected to the IR sensor output
const int buzzerPin = 3; // Digital pin connected to the buzzer

void setup() {
  // Initialize the IR sensor pin as an input
  pinMode(irSensorPin, INPUT);
  // Initialize the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
  // Start the serial communication for debugging purposes
  Serial.begin(9600);
}

void loop() {
  // Read the state of the IR sensor
  int sensorValue = digitalRead(irSensorPin);

  // If the sensor detects an object (output is HIGH)
  if (sensorValue == HIGH) {
    // Turn on the buzzer
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Visitor detected! Buzzer ON.");
  } else {
    // Turn off the buzzer
    digitalWrite(buzzerPin, LOW);
    Serial.println("No visitor. Buzzer OFF.");
  }

  // Short delay to avoid rapid changes
  delay(100);
}
