/***********************************************************
Description: Blinking an LED
Author: Azhar Paraouty
Date: 26/06/2026
***********************************************************/

int ledPin=8; // LED connected to digital pin 8
void setup()
{
  pinMode(ledPin,OUTPUT);    // Configure pin 8 to OUTPUT mode
}

void loop()
{  
  digitalWrite(ledPin,HIGH); // HIGH is set to about 5V PIN 8 -> LED ON
  delay(1000);               // Set the delay time, 1000ms = 1s

  digitalWrite(ledPin,LOW);  // LOW is set to about 0V PIN 8 -> LED OFF
  delay(1000);               // Set the delay time, 1000ms = 1s
} 