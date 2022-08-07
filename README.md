# Arduino TIL311 Tester
An Arduino sketch for testing TIL311/DIS1417 display modules.

  Displays values 0 to F on the display.
  Blanking tested by applying PWM to the blanking pin.

  Written for Arduino Mega.
  Arduino IDE version 1.8.19
  
  #### Connections between Arduino and TIL311:
  
| Arduino Mega Pin | AVR Port | TIL311 Pin No          | TIL311 Pin Function |
|------------------|----------|------------------------|---------------------|
| 22               | PA0      | 3                      | Data A              |
| 23               | PA1      | 2                      | Data B              |
| 24               | PA2      | 13                     | Data C              |
| 25               | PA3      | 12                     | Data D              |
| 26               | PA4      | 4 (Via 680r resistor)  | Left Decimal Point  |
| 27               | PA5      | 10 (Via 680r resistor) | Right Decimal Point |
| 28               | PA6      | 5                      | Strobe              |
| 4                | N/A      | 8                      | Blanking            |

| TIL311 connections:                                           |
|---------------------------------------------------------------|
| Pin 1 to +5v (LED Power Supply)                               |
| Pin 7 to GND (Common Ground)                                  |
| Pin 14 to +5v (Logic Power Supply)                            |
