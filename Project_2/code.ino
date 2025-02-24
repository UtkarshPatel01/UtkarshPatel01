// Program for Switching ON and OFF LED using a clap switch
const int soundSensorPin = 7;             // Pin connected to the sound sensor output
const int ledPin = 12;                    // Pin connected to the LED

// Variables for tracking clap detection
bool ledState = LOW;                      // Initial LED state is off
unsigned long lastClapTime = 0;           // Time of the last clap

const unsigned long debounceDelay = 200;  // Debounce delay to avoid multiple detections

void setup() {
  pinMode(soundSensorPin, INPUT);         // Set sound sensor pin as input
  pinMode(ledPin, OUTPUT);                // Set LED pin as output
  Serial.begin(9600);                     // Begin serial communication (Baud Rate)
}

void loop() {
  int sensorValue = digitalRead(soundSensorPin); // Read the sound sensor

  if (sensorValue == HIGH) {
    unsigned long currentTime = millis();

    // Debounce to prevent multiple detections for a single clap
    if (currentTime - lastClapTime > debounceDelay) {
      ledState = !ledState;             // Toggle the LED state
      digitalWrite(ledPin, ledState);   // Update the LED
      lastClapTime = currentTime;       // Update last clap time
      Serial.println("Clap detected!"); // Printing to Serial Monitor
    }
  }
}
