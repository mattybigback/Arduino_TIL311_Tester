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
  26 / PA4          4 (via 680r resistor)
  27 / PA5          10 (via 680r resistor)
  28 / PA6          5
  4                 8

  TIL311 connections:
  Pin 1 to +5v                    (LED Power Supply)
  Pin 7 to GND                    (Common Ground)
  Pin 14 to +5v                   (Logic Power Supply)
*/

#define DATA_PINS     0b00001111 // Pins 22-25
#define L_DP          0b00010000 // Pin 26
#define R_DP          0b00100000 // Pin 27
#define STROBE        0b01000000 // Pin 28
#define BLANKING      4

byte digit = 0;

void setup() {
  PORTA &= ~DATA_PINS;        // Set all data pins to 0
  PORTA &= ~STROBE;           // Set STROBE high
  PORTA |= L_DP;              // Set left dec. point high
  PORTA &= ~R_DP;             // Set right dec. point low
  analogWrite(BLANKING, 255); // Blank display (active low)
  DDRA = 0b11111111;          // Set PORTA as output
}

void loop() {
  if (digit < 16){
    PORTA &= ~DATA_PINS;              // Clear data pins
    PORTA |= digit;                   // Set data pins to value of digit variable
    PORTA ^= L_DP;                    // Toggle left dec. point
    PORTA ^= R_DP;                    // Toggle right dec. point
    PORTA &= ~STROBE;                 // Set strobe low
    PORTA |= STROBE;                  // Set strobe high

    // Fade display using PWM.
    for (byte i=0; i < 255; i++){
      analogWrite(BLANKING, 255-i);
      if (i < 40){
        delay(8);
      } else {
        delay(4);
      }
    }

    delay(200);                       // Hold display at full brightness for 200 ms
    analogWrite(BLANKING, 255);       // Blank display
    delay(200);                       // Keep display off for 200 ms
    digit++;                          // Increment digit variable
  } else {
    digit = 0;
  }
}
