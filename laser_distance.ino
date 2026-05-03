#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <VL53L0X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
VL53L0X sensor;

void setup() {
  Serial.begin(115200);

  Wire.begin(D2, D1); // SDA, SCL

  // OLED Init
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while(1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Sensor Init
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();

  display.setCursor(0,0);
  display.println("VL53L0X Ready");
  display.display();
  delay(2000);
}

void loop() {
  int distance = sensor.readRangeContinuousMillimeters();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" mm");

  display.clearDisplay();
  display.setCursor(0,5);
  display.setTextSize(1);
  display.println("Distance:");

  display.setTextSize(2);
  display.setCursor(0,26);
  display.print(distance);
  display.println(" mm");

  display.display();

  delay(200);
}