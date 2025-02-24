#include <LiquidCrystal_I2C.h>
#include <Threewire.h>
#include <RtcDS1302.h>

LiquidCrystal_I2C lcd (0x3F, 16, 2);
Threewire mywire (7,6,8); // DATA, CLK, RST
RtcDS1302<Threewire> Rtc (mywire);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  Rtc.Begin();

  RtcDateTime currentTime = RtcDateTime(_DATE_,_TIME_); // Set current date and time
  Rtc.SetDateTime(currentTime); 
}

void loop(){
  RtcDateTime now = Rtc.GetDateTime(); // Get current date and time

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Date: ");
  lcd.print(now.Day());
  lcd.print("/");
  lcd.print(now.Month());
  lcd.print("/");
  lcd.print(now.Year());
  lcd.setCursor(0,1);
  lcd.print("Time: ");
  lcd.print(now.Hour());
  lcd.print(":"); 
  lcd.print(now.Minute());
  lcd.print(":");
  lcd.print(now.Second());
  delay(500);
}
