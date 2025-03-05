// Include necessary libraries
#include <Wire.h>

// Define pin connections
const int trigPin = 12;  // GPIO pin connected to the HC-SR04 Trig pin
const int echoPin = 14;  // GPIO pin connected to the HC-SR04 Echo pin
const int stepPin = 26;  // GPIO pin connected to the A4988 STEP pin
const int dirPin = 25;   // GPIO pin connected to the A4988 DIR pin

// Variables for distance calculation
long duration;
int distance;

void setup() {
  // Set up the pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(115200);

  // Set initial motor direction
  digitalWrite(dirPin, HIGH);  // Set motor direction clockwise
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin and calculate the duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If an obstacle is detected within 20 cm, move the stepper motor backward
  if (distance < 20) {
    Serial.println("Obstacle detected! Moving backward.");
    digitalWrite(dirPin, LOW);  // Set motor direction counterclockwise

    // Move the motor a few steps backward
    for (int i = 0; i < 200; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(500);  // Adjust delay for motor speed
      digitalWrite(stepPin, LOW);
      delayMicroseconds(500);  // Adjust delay for motor speed
    }
  } else {
    // If no obstacle, move the stepper motor forward
    Serial.println("No obstacle. Moving forward.");
    digitalWrite(dirPin, HIGH);  // Set motor direction clockwise

    // Move the motor a few steps forward
    for (int i = 0; i < 200; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(500);  // Adjust delay for motor speed
      digitalWrite(stepPin, LOW);
      delayMicroseconds(500);  // Adjust delay for motor speed
    }
  }

  // Small delay to avoid rapid changes
  delay(500);
}
