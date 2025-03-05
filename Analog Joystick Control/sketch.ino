#include <Adafruit_NeoPixel.h>

#define PIN 6 // Pin connected to the Data In of the NeoPixel ring
#define NUMPIXELS 16 // Number of LEDs in the ring
#define JOYSTICK_X A0 // Analog pin connected to the joystick's VRx
#define JOYSTICK_Y A1 // Analog pin connected to the joystick's VRy
#define JOYSTICK_SW 2 // Digital pin connected to the joystick's switch

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // Initialize the NeoPixel library
  pinMode(JOYSTICK_SW, INPUT_PULLUP); // Set the switch pin as input with pull-up resistor
  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(JOYSTICK_X); // Read the horizontal value
  int yValue = analogRead(JOYSTICK_Y); // Read the vertical value
  int swValue = digitalRead(JOYSTICK_SW); // Read the switch value

  // Map the joystick values to the number of LEDs
  int xMapped = map(xValue, 0, 1023, 0, NUMPIXELS);
  int yMapped = map(yValue, 0, 1023, 0, NUMPIXELS);

  // Set the color of the LEDs based on the joystick position
  for (int i = 0; i < NUMPIXELS; i++) {
    if (i == xMapped || i == yMapped) {
      pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // Set the color to red
    } else {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Turn off the other LEDs
    }
  }

  pixels.show(); // Update the LEDs

  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" Y: ");
  Serial.print(yValue);
  Serial.print(" SW: ");
  Serial.println(swValue);

  delay(100); // Short delay to avoid rapid changes
}
