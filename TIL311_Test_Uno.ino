/*
  TIL311 / DIS1417 Tester
  Matt Harrison
  http://m-harrison.org
  https://github.com/mattybigback/

  Displays values 0 to F on the display.
  Blanking tested by applying PWM to the blanking pin.

  Written on Arduino Uno.
  Arduino IDE version 1.8.19
  
  Connections between Arduino and TIL311:
  
  Arduino Pin       TIL311 Pin
  8   / PB0         DATA A - 3
  9   / PB1         DATA B - 2
  10  / PB2         DATA C - 13
  11  / PB3         DATA D - 12
  5   / PD5         LEFT DEC. PT - 4 (via 680r resistor)
  6   / PD6         RIGHT DEC. PT - 10 (via 680r resistor)
  7   / PD7         STROBE - 5
  3                 BLANKING - 8

  TIL311 connections:
  Pin 1 to +5v                    (LED Power Supply)
  Pin 7 to GND                    (Common Ground)
  Pin 14 to +5v                   (Logic Power Supply)
*/

#define DATA_PINS     0b00001111 // Pins 8-11
#define L_DP          0b00100000 // Pin 5
#define R_DP          0b01000000 // Pin 6
#define STROBE        0b10000000 // Pin 7
#define BLANKING      3

void setup() {
  //Serial.begin(9600);
  PORTB &= ~DATA_PINS;        // Set all data pins to 0
  PORTD &= ~STROBE;           // Set STROBE high
  PORTD |= L_DP;              // Set left dec. point high
  PORTD &= ~R_DP;             // Set right dec. point low
  analogWrite(BLANKING, 255); // Blank display (active low)
  DDRB |= 0b00101111;         // Set PORTB bits 0-3 and 5 as output (bit 5 is Arduino Uno LED)
  DDRD |= 0b11111000;          // Set PORTD bits 3-7 as output 
}

void loop() {

for(byte i=0; i < 16; i++){  
    PORTB &= ~DATA_PINS;              // Clear data pins
    PORTB |= i;                   // Set data pins to value of digit variable
    PORTD ^= L_DP;                    // Toggle left dec. point
    PORTD ^= R_DP;                    // Toggle right dec. point
    PORTD &= ~STROBE;                 // Set strobe low
    PORTD |= STROBE;                  // Set strobe high

    // Fade display using PWM.
    byte dutyCycle = 255;
    do {
      analogWrite(BLANKING, dutyCycle);
      delay(5);
      dutyCycle--;
    } while (dutyCycle != 255);

    delay(200);                       // Hold display at full brightness for 200 ms
    analogWrite(BLANKING, 255);       // Blank display
    delay(200);                       // Keep display off for 200 ms

  }
}
