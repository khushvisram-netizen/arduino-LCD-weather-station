# Arduino Digital Weather Station with LCD & Alarm (Indoor and Outdoor Use)

A beginner-friendly Arduino weather station built using the Elegoo UNO R3 Super Starter Kit. It reads ambient temperature and humidity using a DHT11 sensor, displays real-time calibrated measurements on a 1602 LCD, and triggers an active buzzer alarm when a temperature threshold is exceeded.

## Hardware Components
* Elegoo UNO R3 Board
* LCD1602 Display Module
* B103 (10k) Thumbwheel Potentiometer
* DHT11 Temperature & Humidity Sensor
* Active Buzzer
* Breadboard and Jumper Wires
* 5V Power Source

## Wiring Connections

### 1. LCD1602 Module
* **VSS** -> GND
* **VDD** -> 5V
* **VO** -> Potentiometer Middle Pin Row
* **RS** -> Arduino Pin 7
* **RW** -> GND
* **E** -> Arduino Pin 8
* **D4** -> Arduino Pin 9
* **D5** -> Arduino Pin 10
* **D6** -> Arduino Pin 11
* **D7** -> Arduino Pin 12
* **A (Anode)** -> 220Ω Resistor -> 5V
* **K (Cathode)** -> GND

### 2. B103 Potentiometer
* **Top Pin** -> 5V
* **Middle Pin** -> LCD VO (Pin 3)
* **Bottom Pin** -> GND

### 3. DHT11 Sensor
* **VCC (+)** -> 5V
* **DATA (Out)** -> Arduino Pin 2
* **GND (-)** -> GND

### 4. Active Buzzer
* **Positive (+)** -> Arduino Pin 3
* **Negative (-)** -> GND

## Features & Calibration
* Converts raw Celsius readings to **Fahrenheit**.
* Built-in calibration offset variables (`TEMP_OFFSET` and `HUMIDITY_OFFSET`) to correct sensor drift.
* High-temperature alert buzzer trigger.

## Required Libraries
Install via Arduino IDE Library Manager:
* `DHT sensor library` by Adafruit
* `LiquidCrystal` (built-in)
