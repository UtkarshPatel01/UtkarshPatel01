int control = 5;

//For delay
unsigned long counta = 0;
unsigned long countb = 0;
unsigned long countc = 0;
unsigned long count = 9600; 

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(control, OUTPUT);
  digitalWrite(control, LOW);
  delay(3000); // Delay at starting

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValuea = analogRead(A0);
  int sensorValueb = analogRead(A1);
  int sensorValuec = analogRead(A2);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltagea = sensorValuea * (5.0 / 1023.0);
  float voltageb = sensorValueb * (5.0 / 1023.0);
  float voltagec = sensorValuec * (5.0 / 1023.0);
  // print out the value you read:
  //Serial.println(voltagea);
  //Serial.println(voltageb);
  //Serial.println(voltagec);
  //Serial.println("............");
  //Serial.println(counta);
  //Serial.println("............");
  

  if ((voltagea < 3)) {
    //digitalWrite(control, HIGH);
    counta = counta + 1UL;
    if (counta > count) {
      digitalWrite(control, HIGH);
    }

  }
  else if ((voltageb < 3)) {
    //digitalWrite(control, HIGH);\
    countb = countb + 1UL;
    if (countb > count) {
      digitalWrite(control, HIGH);
    }

  }
  else if ((voltagec < 3)) {
    //digitalWrite(control, HIGH);
    countc = (countc + 1UL);
    if (countc > count) {
      digitalWrite(control, HIGH);
    }
  }

  else
  {
    int s = analogRead(A3);
    //Serial.println(s);
    Serial.println("............");

    if (s == 1023)
    {
      digitalWrite(control, LOW);
      counta = 0;
      countb = 0;
      countc = 0;

    }
  }
}
