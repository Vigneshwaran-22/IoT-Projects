// Define the pin connections
const int gasSensorPin = A0; // Analog pin connected to the gas sensor's AO
const int buzzerPin = 13; // Digital pin connected to the buzzer

void setup() {
  // Initialize the gas sensor pin as an input
  pinMode(gasSensorPin, INPUT);
  // Initialize the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
  // Start the serial communication for debugging purposes
  Serial.begin(115200);
}

void loop() {
  // Read the analog value from the gas sensor
  int sensorValue = analogRead(gasSensorPin);
  
  // Print the sensor value to the Serial Monitor for debugging
  Serial.println(sensorValue);
  
  // Adjust the threshold value according to your needs
  // If the sensor value exceeds the threshold (indicating gas leakage)
  if (sensorValue > 300) {
    // Turn on the buzzer
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Gas detected! Buzzer ON.");
  } else {
    // Turn off the buzzer
    digitalWrite(buzzerPin, LOW);
    Serial.println("No gas detected. Buzzer OFF.");
  }

  // Short delay to avoid rapid changes
  delay(100);
}
