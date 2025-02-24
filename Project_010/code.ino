#include <Servo.h>

Servo myServo;            // Servo motor object
const int trigPin = 2;    // Trigger pin of HC-SR04
const int echoPin = 3;    // Echo pin of HC-SR04
int servoAngle = 0;       // Angle of servo motor

void setup() {
  Serial.begin(9600);     // Initialize Serial Monitor
  myServo.attach(9);      // Attach servo to pin 9
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  for (servoAngle = 0; servoAngle <= 180; servoAngle += 2) {
    myServo.write(servoAngle); // Rotate servo to angle
    delay(30);                 // Allow servo to move
    float distance = measureDistance();
    Serial.print("Angle: ");
    Serial.print(servoAngle);
    Serial.print(" Distance: ");
    Serial.println(distance);
  }

  for (servoAngle = 180; servoAngle >= 0; servoAngle -= 2) {
    myServo.write(servoAngle); // Rotate servo back
    delay(30);                 // Allow servo to move
    float distance = measureDistance();
    Serial.print("Angle: ");
    Serial.print(servoAngle);
    Serial.print(" Distance: ");
    Serial.println(distance);
  }
}

// Measure distance using HC-SR04
float measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.034) / 2; // Convert to cm
  return distance;
}
