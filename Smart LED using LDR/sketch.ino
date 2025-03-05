const int ldrPin = A0; // Analog pin connected to the LDR
const int ledPin = 9; // Digital pin connected to the LED

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin); // Read the value from the LDR
  Serial.println(ldrValue); // Print the LDR value to the Serial Monitor

  // Adjust the threshold value according to your needs
  if (ldrValue < 500) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED
  }
  delay(100); // Short delay to avoid rapid changes
}
