#include <LiquidCrystal.h>
#include <DHT.h>

// Initialize LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

#define DHTPIN 2       // DHT11 connected to pin 2
#define DHTTYPE DHT11  // DHT 11 sensor type
#define BUZZER_PIN 3   // Buzzer connected to pin 3
#define TEMP_THRESHOLD_F 80.0 // High temp alert threshold in fahrenheit

// CALIBRATION
// Adjust these numbers based on your actual readings
#define TEMP_OFFSET -3.3      // change value to adjust temp readings
#define HUMIDITY_OFFSET 7.0  // change value to adjust humidity readings

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Welcome Message
  lcd.print("Weather Station");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  float rawHumidity = dht.readHumidity();
  float rawTempF = dht.readTemperature(true); // Read in Fahrenheit

  // Check if readings failed
  if (isnan(rawHumidity) || isnan(rawTempF)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    return;
  }

  // Apply Calibration Offsets
  float tempF = rawTempF + TEMP_OFFSET;
  float humidity = rawHumidity + HUMIDITY_OFFSET;

  // limit humidity between 0% and 100% just in case
  humidity = constrain(humidity, 0.0, 100.0);

  // Display Temperature(f)
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempF, 1);
  lcd.print((char)223); // Degree symbol
  lcd.print("F  ");

  // Display Humidity
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity, 0);
  lcd.print("%  ");

  // Temperature Alarm Logic (f)
  if (tempF >= TEMP_THRESHOLD_F) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(2000); // Sensor update interval
}
