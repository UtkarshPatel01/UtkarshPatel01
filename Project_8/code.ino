#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); 

// Measuring Current Using ACS712
int sensitivity = 185; // using 185 for 5A Module
int offsetvoltage = 2500; // Sensor calibration
int adcvalue= 0;

// voltage measuring
// Current measuring
double ecurrent = 0;
double Voltage = 0;

void setup()
{
  lcd.begin(20, 4);
  lcd.setCursor(0,0);
  lcd.print(" Utkarsh Patel"); 
  lcd.setCursor(0,1);
  lcd.print(" SOLAR MONITOR"); 
}

void loop()
{
  // Measuring The Voltage 
  // reading the input on analog pin A1:
  int sensorValue = analogRead(A1); 

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float vol = (sensorValue * 5.0) / 1023.0; 
  float voltage = vol * 5;
  lcd.setCursor(0,2);
  lcd.print(" Voltage = ");
  lcd.print(voltage);
  lcd.print("V");

// Measuring The Current ***************************************************
  adcvalue = analogRead(A0);  //reading the value from the analog pin A0
  Voltage = (adcvalue / 1024.0) * 5000; // Gets you mV
  ecurrent = ((Voltage - offsetvoltage) / sensitivity);

  lcd.setCursor(0,3);
  lcd.print(" Current = ");
  lcd.print(ecurrent);
  lcd.print("A"); //unit for the current to be measured
  delay(2000);
}
