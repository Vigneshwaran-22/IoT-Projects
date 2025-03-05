#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <MPU6050.h>

// Pin definitions
#define NEOPIXEL_PIN 6       // Data pin for NeoPixel
#define NUMPIXELS 16         // Number of LEDs in the NeoPixel strip

// Initialize the NeoPixel object
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

// Initialize the MPU6050 object
MPU6050 mpu;

void setup() {
  // Start the serial communication for debugging purposes
  Serial.begin(9600);
  
  // Initialize the NeoPixel strip
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
  // Initialize the MPU6050 sensor
  Wire.begin();
  mpu.initialize();
  
  // Check if the MPU6050 is connected
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connected successfully!");
  } else {
    Serial.println("MPU6050 connection failed!");
  }
}

void loop() {
  // Variables to hold accelerometer data
  int16_t ax, ay, az;
  
  // Read the accelerometer data
  mpu.getAcceleration(&ax, &ay, &az);
  
  // Print the accelerometer data for debugging purposes
  Serial.print("aX = "); Serial.print(ax);
  Serial.print(" | aY = "); Serial.print(ay);
  Serial.print(" | aZ = "); Serial.println(az);
  
  // Map the accelerometer data to LED index
  int ledIndex = map(ax, -17000, 17000, 0, NUMPIXELS - 1);
  
  // Ensure the mapped value is within the LED strip range
  ledIndex = constrain(ledIndex, 0, NUMPIXELS - 1);
  
  // Clear all LEDs
  strip.clear();
  
  // Set the color of the LED based on the gesture
  strip.setPixelColor(ledIndex, strip.Color(255, 0, 0)); // Red color for demonstration
  
  // Show the updated colors on the LED strip
  strip.show();
  
  // Small delay to avoid rapid changes
  delay(100);
}
