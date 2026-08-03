/***********************************************************
Description: Sending ‘1’ or ‘0’ on the serial monitor, 
             will change the state of LED.
             Either ON (1) or OFF (0) 
Author: Azhar
Date: 03/08/2026
***********************************************************/

int ledpin=8;             // LED connected to and controlled by digital pin 8.

void setup() {
  Serial.begin(9600);     // Opens Serial Port, sets data rate to 9600 bps
  pinMode(ledpin,OUTPUT); // Configure pin 8 to OUTPUT mode
}

void loop() {
 
  char receivedValue;    

  if(Serial.available() > 0) {
    receivedValue = Serial.read();  // Store the received data (1 | 0) in the variable

    if(receivedValue == '1') {      // If User types 1 on their PC ...
      digitalWrite(ledpin, HIGH);   // ... light the LED ON
      Serial.println("LED:ON");
    }

    if(receivedValue == '0') {     // If User types 0 on their PC ...
      digitalWrite(ledpin, LOW);   // ... turn the LED OFF
      Serial.println("LED:OFF");
    }
  }

  delay(50);  // Wait for a few milliseconds
}