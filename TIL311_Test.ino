/*
  TIL311 / DIS1417 Tester
  Matt Harrison
  http://m-harrison.org
  https://github.com/mattybigback/

  Displays values 0 to F on the display.
  Blanking tested by applying PWM to the blanking pin.

  Written on Arduino Mega.
  Arduino IDE version 1.8.19
  
  Connections between Arduino and TIL311:
  
  Arduino Pin       TIL311 Pin
  22 / PA0          3
  23 / PA1          2
  24 / PA2          13
  25 / PA3          12
  3                 5
  4                 8

  TIL311 connections:
  Pin 1 to +5v                    (LED Power Supply)
  Pin 4 to +5v via 680r resistor  (Left decimal point cathode)
  Pin 7 to GND                    (Common Ground)
  Pin 10 to +5v via 680r resistor (Right decimal point cathode)
  Pin 14 to +5v                   (Logic Power Supply)
*/

#define STROBE 3
#define BLANKING 4

  byte digit = 0;

void setup() {
DDRA = 0b00001111;          // Set PORTA BITS 0 TO 3 AS OUTPUT
pinMode(STROBE, OUTPUT);
pinMode(BLANKING, OUTPUT);
digitalWrite(STROBE, HIGH);   // Pull strobe pin high
digitalWrite(BLANKING, HIGH);  // Pull dimming pin high
}

void loop() {
  if (digit < 16){
    PORTA = digit;
    delay(1);
    digitalWrite(STROBE, LOW);
    delay(1);
    digitalWrite(STROBE, HIGH);
    for (byte i=0; i < 255; i++){
      analogWrite(BLANKING, 255-i);
      if (i < 30){
        delay(15);
      } else {
        delay(4);
      }
    }
    delay(200);
    digitalWrite(BLANKING, HIGH);
    delay(200);
    digit++;
  } else {
    digit = 0;
  }
}
