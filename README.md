
# 📏 ESP8266 + VL53L0X Distance Sensor with OLED Display

This project demonstrates how to measure distance using the **VL53L0X Time-of-Flight (ToF) sensor** and display the values in real-time on an **SSD1306 OLED display** using an ESP8266 (NodeMCU).

---

## 🚀 Features
- 📡 Accurate distance measurement using laser ToF sensor  
- 📟 Real-time display on OLED (128x64)  
- 🔄 Continuous measurement mode  
- 🔌 I2C communication (shared bus for sensor + display)  
- 🖥️ Serial monitor output for debugging  

---

## 🧰 Components Used
- ESP8266 NodeMCU  
- VL53L0X Distance Sensor  
- SSD1306 OLED Display (I2C)  
- Jumper wires  

---

## 🔌 Circuit Connections

| Device | ESP8266 Pin |
|--------|------------|
| VCC    | 3.3V |
| GND    | GND |
| SDA    | D2 (GPIO4) |
| SCL    | D1 (GPIO5) |

> Both OLED and VL53L0X share the same I2C lines.

---

## 📚 Libraries Required
Install the following libraries in Arduino IDE:

- Adafruit SSD1306  
- Adafruit GFX  
- VL53L0X (Pololu or Adafruit)

---

## 💻 Code

```cpp
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
  Wire.begin(D2, D1);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while(1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

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
  display.setCursor(0,0);
  display.setTextSize(1);
  display.println("Distance:");

  display.setTextSize(2);
  display.setCursor(0,20);
  display.print(distance);
  display.println(" mm");

  display.display();

  delay(200);
}
