#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
int tempPin = A0;         // the output pin of LM35
int fan = 11;             // the pin where fan is
int led = 8;              // led pin
int temp;                 // temperature
int tempMin = 15;         // the temperature to start the fan at 0%
int tempMax = 100;        // the maximum temperature when fan is at 100%
int fanSpeed;
int fanLCD;

void setup()
{
  pinMode(fan, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(tempPin, INPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
  temp = readTemp();      // get or store the temperature
  Serial.print(temp);
  if(temp < tempMin)      // if temp is lower than minimum temp
  {
    fanSpeed = 0;
    analogWrite(fan, fanSpeed);
    fanLCD = 0;
    digitalWrite(fan, LOW);
  }

  if((temp >= tempMin) && (temp <= tempMax)) // if temperature is higher than minimum temp
  {
    fanSpeed = temp;
    fanSpeed = 1.5 * fanSpeed;
    fanLCD = map(temp, tempMin, tempMax, 0, 100); // speed of fan to display on LCD100
    analogWrite(fan, fanSpeed);                  // spin the fan at the fanSpeed speed
  }

  else if(temp > tempMax) // if temp is higher than tempMax
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }

    lcd.print("TEMP: ");    // To display the temperature
    lcd.print(temp);
    lcd.print("C");
    lcd.setCursor(0,1);     // To move cursor to next line
    lcd.print("FANS: ");    // To display the fan speed
    lcd.print(fanLCD);
    lcd.print("%");
    delay(200);
    lcd.clear();
}

int readTemp()
{
  // get the temperature and convert it to celsius
  temp = analogRead(tempPin);
  return temp * 0.48828125;
}
