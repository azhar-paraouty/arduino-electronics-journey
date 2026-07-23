/***********************************************************
Description: When the relay switches, the LED will light up; 
             When the relay breaks, the LED will go out.
Author: Azhar Paraouty
Date: 07/07/2026
***********************************************************/
const int relayPin = 8;         // Energizes the coil pins of the Relay

void setup()
{
  pinMode(relayPin, OUTPUT);    // Configure pin 8 to OUTPUT mode
}

void loop()                     // Repeatedly switch the Relay's path
{
  digitalWrite(relayPin, HIGH); // Switch relay to Normally Open (NO) Pin.
  delay(1000);                  // Wait for a second

  digitalWrite(relayPin, LOW);  // Switch relay back to Normally Closed (NC) Pin.
  delay(1000);                  // Wait for a second
}