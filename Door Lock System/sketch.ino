#include <Keypad.h>
#include <Servo.h>

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Servo myServo;

const String password = "1234";
String inputPassword;

void setup() {
  Serial.begin(9600);
  myServo.attach(10); // Servo connected to pin D10
  myServo.write(0); // Lock position
  Serial.println("Enter Password:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print(key);
    if (key == '#') {
      if (inputPassword == password) {
        Serial.println("\nAccess Granted");
        myServo.write(90); // Unlock position
        delay(5000); // Keep the door unlocked for 5 seconds
        myServo.write(0); // Lock position
      } else {
        Serial.println("\nAccess Denied");
      }
      inputPassword = ""; // Clear the input password
    } else {
      inputPassword += key; // Append the key to the input password
    }
  }
}
