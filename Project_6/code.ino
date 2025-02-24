// Motor 1 pins
const int motor1Pin1 = 2;
const int motor1Pin2 = 3;
const int motor1PWM = 5;

// Motor 2 pins
const int motor2Pin1 = 4;
const int motor2Pin2 = 7;
const int motor2PWM = 6;

// Motor 3 pins
const int motor3Pin1 = 8;
const int motor3Pin2 = 9;
const int motor3PWM = 10;

// Motor 4 pins
const int motor4Pin1 = 11;
const int motor4Pin2 = 12;
const int motor4PWM = 13;

void setup() {
  // Set motor control pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor1PWM, OUTPUT);

  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor2PWM, OUTPUT);

  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);
  pinMode(motor3PWM, OUTPUT);

  pinMode(motor4Pin1, OUTPUT);
  pinMode(motor4Pin2, OUTPUT);
  pinMode(motor4PWM, OUTPUT);

  // Initialize all motors in the same direction
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW);
}

void loop() {
  // Set all motors to full speed
  analogWrite(motor1PWM, 255);
  analogWrite(motor2PWM, 255);
  analogWrite(motor3PWM, 255);
  analogWrite(motor4PWM, 255);
}
