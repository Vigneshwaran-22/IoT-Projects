#include <IRremote.h>

const int irPin = 14; // GPIO pin connected to the IR receiver
const int buzzerPin = 13; // GPIO pin connected to the buzzer

IRrecv irrecv(irPin);
decode_results results;

void setup() {
  irrecv.enableIRIn(); // Start the receiver
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  Serial.begin(115200);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); // Print the received IR code in hexadecimal
    
    switch (results.value) {
      case 0xFFA25D: // Example IR code for a specific button
        tone(buzzerPin, 1000, 500); // Play a tone at 1000Hz for 500ms
        break;
      case 0xFF629D: // Another example IR code
        tone(buzzerPin, 2000, 500); // Play a tone at 2000Hz for 500ms
        break;
      // Add more cases for different buttons if needed
      default:
        noTone(buzzerPin); // Turn off the buzzer for unrecognized codes
        break;
    }
    irrecv.resume(); // Receive the next value
  }
}
