#define SOIL_SENSOR_PIN A0
#define PUMP_PIN 3

int threshold = 500;           // Adjust based on sensor calibration

void setup() {
    pinMode(PUMP_PIN, OUTPUT);
    digitalWrite(PUMP_PIN, LOW);
    Serial.begin(9600);
}

void loop() {
    int moistureLevel = analogRead(SOIL_SENSOR_PIN);
    Serial.print("Soil Moisture: ");
    Serial.println(moistureLevel);

    if (moistureLevel < threshold) {
        digitalWrite(PUMP_PIN, HIGH); // Turn on the pump
        Serial.println("Pump ON");
    } else {
        digitalWrite(PUMP_PIN, LOW);  // Turn off the pump
        Serial.println("Pump OFF");
    }
    delay(1000);                 
}
