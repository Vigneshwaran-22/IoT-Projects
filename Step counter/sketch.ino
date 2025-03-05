#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <MPU6050.h>

// OLED display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Declaration for SSD1306 display connected using I2C (SDA, SCL)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// MPU6050 sensor
MPU6050 mpu;
int stepCounter = 0;
bool isStep = false;

void setup() {
  // Start the serial communication
  Serial.begin(115200);
  
  // Initialize the MPU6050 sensor
  Wire.begin();
  mpu.initialize();
  
  // Check if the MPU6050 is connected
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connected successfully!");
  } else {
    Serial.println("MPU6050 connection failed!");
  }

  // Initialize the OLED display
  if (!display.begin(SSD1306_I2C_ADDRESS, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  // Variables to hold accelerometer data
  int16_t ax, ay, az;

  // Read the accelerometer data
  mpu.getAcceleration(&ax, &ay, &az);

  // Simple step detection logic (you may need to adjust thresholds)
  if (abs(ax) > 15000 && !isStep) {
    stepCounter++;
    isStep = true;
  } else if (abs(ax) < 15000) {
    isStep = false;
  }

  // Display step count on the OLED
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Step Count: ");
  display.print(stepCounter);
  display.display();

  // Small delay to avoid rapid changes
  delay(100);
}
