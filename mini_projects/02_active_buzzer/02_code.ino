/***********************************************************
Description: Continuous buzzer beep sound.
Author: Azhar Paraouty
Date: 01/07/2026
***********************************************************/
int buzzerPin=8; // Buzzer Pin connected to digital pin 8
void setup()
{
  pinMode(buzzerPin,OUTPUT); // Configure pin 8 to Control the Buzzer
}
void loop()
{  
  for (int i = 0; i < 10; i++) {
    digitalWrite(buzzerPin,HIGH); // Set PIN 8 feet as HIGH = 5 v 
    delay(100);                   // Set the delay time，100ms 

    digitalWrite(buzzerPin,LOW);  // Set PIN 8 feet for LOW = 0 v 
    delay(100);                   // Set the delay time，100ms
  }

  digitalWrite(buzzerPin,HIGH);   // Set PIN 8 feet as HIGH = 5 v 
  delay(1000);                    // Set the delay time，1000ms 

  digitalWrite(buzzerPin,LOW);    // Set PIN 8 feet for LOW = 0 v 
  delay(1000);                    // Set the delay time，100ms
}
