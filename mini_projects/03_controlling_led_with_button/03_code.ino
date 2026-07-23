/***********************************************************
Description: When the button is pressed, the state of the
             LED will be toggled. (ON -> OFF，OFF -> ON).
Author: Azhar Paraouty
Date: 02/07/2026
***********************************************************/

int ledPin=8;              // LED connected to digital pin 8
int btnPin=2;              // Set the digital pin 2 to control the LED 

void setup()
{
  pinMode(ledPin, OUTPUT); // Configure pin 8 to OUTPUT mode (sends voltage)
  pinMode(btnPin, INPUT);  // Configure pin 2 to INPUT mode (receives voltage)
}

void loop()
{
  if(digitalRead(btnPin)==HIGH) // When the Circuit is completed, ...
  {
    digitalWrite(ledPin, HIGH); // ... Turn the LED ON.
  }
  else                          // When the Circuit is broken, ...
  {
    digitalWrite(ledPin, LOW);  // ... Keep the LED OFF.
  }
}
