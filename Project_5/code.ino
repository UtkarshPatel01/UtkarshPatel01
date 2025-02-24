#include <Servo.h>
#define echoPin 4
#define trigPin 5
Servo mservo;

int distance;
long duration;

void setup() {
  pinMode(13, OUTPUT);
  mservo.attach(3);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = (duration * 0.034 / 2);

  if (distance <= 15) {
    mservo.write(90);
    digitalWrite(13, HIGH);
  } else {
    mservo.write(0);
    digitalWrite(13, LOW);
  }

  delay(1000);
}
