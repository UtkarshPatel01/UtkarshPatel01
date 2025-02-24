#include <Servo.h>
// Define pins for LDRs
#define LDR1 A0
#define LDR2 A1

// Define error threshold
#define error 10

// Initial servo position
int Spoint = 90;
Servo servo;
void setup() {
  // Attach servo to pin 11
  servo.attach(11);
  // Set initial servo position
  servo.write(Spoint);
  // Wait for 1 second
  delay(1000);
}
void loop() {
  // Read values from LDRs
  int ldr1 = analogRead(LDR1);
  int ldr2 = analogRead(LDR2);

  // Calculate absolute difference between LDR values
  int value1 = abs(ldr1 - ldr2);

  // Check if either LDR value is within the error threshold
  if ((value1 <= error) || (value2 <= error)) {
    // If within threshold, do nothing
  } else {
    // If not within threshold, adjust servo position based on LDR values
    if (ldr1 > ldr2) {
      // If LDR1 value is greater, decrease servo position
      Spoint--;
    } else {
      // If LDR2 value is greater, increase servo position
      Spoint++;
    }
  }
  // Update servo position
  servo.write(Spoint);

  // Wait for 80 milliseconds
  delay(80);
}
