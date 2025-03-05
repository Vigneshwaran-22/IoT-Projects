const int ledPins[] = {10,11,12,13};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100); // Adjust delay to change the speed of the chaser
    digitalWrite(ledPins[i], LOW);
  }
}
