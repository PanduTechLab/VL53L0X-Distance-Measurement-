
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



