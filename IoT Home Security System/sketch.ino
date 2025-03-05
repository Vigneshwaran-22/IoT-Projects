// Define the pin connections
const int pirPin = 13; // GPIO pin connected to the PIR sensor output
const int buzzerPin = 12; // GPIO pin connected to the buzzer

void setup() {
  // Set up the PIR sensor pin as an input
  pinMode(pirPin, INPUT);
  // Set up the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
  // Start the serial communication for debugging purposes
  Serial.begin(115200);
  // Connect to WiFi network
  WiFi.begin("your_SSID", "your_PASSWORD");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void loop() {
  // Read the state of the PIR sensor
  int sensorValue = digitalRead(pirPin);

  // If the sensor detects motion (output is HIGH)
  if (sensorValue == HIGH) {
    // Turn on the buzzer
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Motion detected! Buzzer ON.");
    // Send alert to a server (example URL)
    WiFiClient client;
    if (client.connect("example.com", 80)) {
      client.print("GET /alert?motion=detected HTTP/1.1\r\n");
      client.print("Host: example.com\r\n");
      client.print("Connection: close\r\n\r\n");
      client.stop();
    }
  } else {
    // Turn off the buzzer
    digitalWrite(buzzerPin, LOW);
    Serial.println("No motion detected. Buzzer OFF.");
  }

  // Small delay to avoid rapid changes
  delay(1000);
}
