/***********************************************************
Description: Using a potentiometer, the Arduino will read
             an analog value and display the corresponding
             number from 0000 to 9999 on a 4-digit display.

Author: Azhar
Date: 01/10/2026
***********************************************************/

// =========================================================
// SEGMENT PINS
// =========================================================
// Each segment of the 7-segment display is connected to
// the Arduino through a 220 Ω current-limiting resistor.

const int A  = 2;
const int B  = 3;
const int C  = 4;
const int D  = 5;
const int E  = 6;
const int F  = 7;
const int G  = 8;
const int DP = 9;


// =========================================================
// DIGIT SELECT PINS
// =========================================================
// These pins control which of the four digits is active.
// The digits are rapidly switched ON and OFF (multiplexing).

const int D1 = 10;
const int D2 = 11;
const int D3 = 12;
const int D4 = 13;


// =========================================================
// SETUP
// =========================================================

void setup() {

  // Configure segment pins as outputs
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);

  // Configure digit-select pins as outputs
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
}


// =========================================================
// TURN ALL SEGMENTS OFF
// =========================================================

void clearSegments() {

  // The display is common-anode, so HIGH turns
  // the individual segments OFF.

  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, HIGH);
}


// =========================================================
// DISPLAY A SINGLE DIGIT
// =========================================================
// Turns ON the required segments to form the number.
// LOW = segment ON
// HIGH = segment OFF
// =========================================================

void showDigit(int number) {

  // Start with all segments OFF
  clearSegments();


  // -------------------------
  // Number 0
  // -------------------------
  if (number == 0) {

    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
  }


  // -------------------------
  // Number 1
  // -------------------------
  else if (number == 1) {

    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
  }


  // -------------------------
  // Number 2
  // -------------------------
  else if (number == 2) {

    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(G, LOW);
  }


  // -------------------------
  // Number 3
  // -------------------------
  else if (number == 3) {

    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(G, LOW);
  }


  // -------------------------
  // Number 4
  // -------------------------
  else if (number == 4) {

    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  }


  // -------------------------
  // Number 5
  // -------------------------
  else if (number == 5) {

    digitalWrite(A, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  }


  // -------------------------
  // Number 6
  // -------------------------
  else if (number == 6) {

    digitalWrite(A, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  }


  // -------------------------
  // Number 7
  // -------------------------
  else if (number == 7) {

    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
  }


  // -------------------------
  // Number 8
  // -------------------------
  else if (number == 8) {

    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  }


  // -------------------------
  // Number 9
  // -------------------------
  else if (number == 9) {

    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  }
}


// =========================================================
// MAIN LOOP
// =========================================================

void loop() {

  // -------------------------------------------------------
  // 1. Read the potentiometer
  // -------------------------------------------------------
  // analogRead() returns a value between 0 and 1023.

  int potValue = analogRead(A0);


  // -------------------------------------------------------
  // 2. Convert the potentiometer value
  // -------------------------------------------------------
  // Convert the 0-1023 analog reading into a number
  // between 0 and 9999.

  int number = map(potValue, 0, 1023, 0, 9999);


  // -------------------------------------------------------
  // 3. Split the number into four individual digits
  // -------------------------------------------------------

  int thousands = number / 1000;
  int hundreds  = (number / 100) % 10;
  int tens      = (number / 10) % 10;
  int ones      = number % 10;


  // -------------------------------------------------------
  // 4. Multiplex the four digits
  // -------------------------------------------------------
  // Only one digit is switched ON at a time.
  // The process happens repeatedly and quickly enough
  // that the human eye perceives all four digits together.


  // ---- Digit 1: Thousands ----

  digitalWrite(D1, HIGH);
  showDigit(thousands);
  delay(5);
  digitalWrite(D1, LOW);


  // ---- Digit 2: Hundreds ----

  digitalWrite(D2, HIGH);
  showDigit(hundreds);
  delay(5);
  digitalWrite(D2, LOW);


  // ---- Digit 3: Tens ----

  digitalWrite(D3, HIGH);
  showDigit(tens);
  delay(5);
  digitalWrite(D3, LOW);


  // ---- Digit 4: Ones ----

  digitalWrite(D4, HIGH);
  showDigit(ones);
  delay(5);
  digitalWrite(D4, LOW);
}