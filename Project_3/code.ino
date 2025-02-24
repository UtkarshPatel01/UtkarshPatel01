#include <SoftwareSerial.h> 
SoftwareSerial SIM900A(10,11); // 10 pin connect to TX of GSM SIM 900 Module
SoftwareSerial( RX , TX );     // 11 pin connect to RX of GSM SIM 900 Module
 
 int val = 0 ; 
void setup() 
{
      Serial.begin(9600);      // sensor baud rate 
      SIM900A.begin(9600);     // GSM baud rate 
      pinMode(4,HIGH);         // LED connect D4 
}
void loop() 
{ 
      val = digitalRead(7);   // IR sensor output pin connected D7 
      Serial.println(val);    // see the value in serial monitor in Arduino IDE
      delay(1000);    
      if (Serial.available()>0) 
         switch(Serial.read()) 
     if (SIM900A.available()>0) 
        Serial.write(SIM900A.read()); 
     if(val == 0 ) // Check your sensor Value 1 or 0 
     { 
          Serial.println ("Obstacle Detecting"); 
          digitalWrite(4,HIGH);               // LED ON    
          Serial.println ("Sending Message"); 
          SIM900A.println("AT+CMGF=1");       //Sets the GSM Module in Text Mode
          delay(1000); 
          Serial.println ("9140660600");
          SIM900A.println("AT+CMGS=\"9140660600\"\r"); //Mobile phone number to send message
          delay(1000); 
          Serial.println ("Set SMS Content"); 
          SIM900A.println("Someone is arrived, be safe");// Message content
          delay(1000); 
          Serial.println ("Finish"); 
          SIM900A.println((char)26);                      // ASCII code of undo
          delay(1000); 
          Serial.println ("Message has been sent "); 
         digitalWrite(4,LOW);                            // LED OFF 
     } 
}

