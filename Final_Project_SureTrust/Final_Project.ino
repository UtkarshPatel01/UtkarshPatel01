#include <LiquidCrystal.h> 
#include <DHT.h>           

// LCD pins connection
const int rs = PB11, en = PB10, d4 = PA4, d5 = PA3, d6 = PA2, d7 = PA1; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 

#define DHTPIN PA0        // Pin for DHT11 data
#define DHTTYPE DHT11     // DHT11 sensor type
DHT dht(DHTPIN, DHTTYPE); // Initializing the DHT sensor

void setup() 
{
  // Initializing the LCD and DHT sensor
  lcd.begin(16, 2);
  dht.begin(); 
  lcd.print("DHT11 with STM32");
  delay(3000); // Wait for message to display
  lcd.clear();
}

void loop() 
{
  // Read sensor data
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Error handling for sensor readings
  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    lcd.setCursor(0, 1);
    lcd.print("Check DHT");
    delay(2000); // Wait before retrying
    return;
  }

  // Display temperature and humidity
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t, 1); // One decimal place
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
  lcd.print(h, 1); // One decimal place
  lcd.print(" %");

  delay(2000); // Update every 2 seconds
}
