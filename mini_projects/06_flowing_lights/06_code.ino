/***********************************************************
Description: Sequential LED lighting control.
             LEDs connected to digital pins 6-9 turn ON one
             after another, then turn OFF one after another.
Author: Azhar Paraouty
Date: 13/08/2026
***********************************************************/

void setup() {
  unsigned char ledPin;    // Variable used to represent LED pins 6-9.

  // Configure digital pins 6, 7, 8, and 9 as OUTPUT pins.
  for (ledPin = 6; ledPin <= 9; ledPin++) {
    pinMode(ledPin, OUTPUT);
  }
}

void loop() {
  unsigned char ledPin;    // Reuse the variable for controlling each LED.

  // Turn LEDs ON one at a time from pin 6 to pin 9.
  for (ledPin = 6; ledPin <= 9; ledPin++) {
    digitalWrite(ledPin, HIGH);   // Set the current LED pin HIGH (LED ON).
    delay(300);                   // Wait 300 milliseconds before the next LED.
  }

  // Turn LEDs OFF one at a time from pin 6 to pin 9.
  for (ledPin = 6; ledPin <= 9; ledPin++) {
    digitalWrite(ledPin, LOW);    // Set the current LED pin LOW (LED OFF).
    delay(300);                   // Wait 300 milliseconds before the next LED.
  }
}