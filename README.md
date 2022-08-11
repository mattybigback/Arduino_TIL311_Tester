# Arduino TIL311 Tester
### An Arduino sketch for testing TIL311/DIS1417 display modules.

  Displays values 0 to F on the display.
  Blanking function tested by applying PWM to the blanking pin.
  Decimal points alternate as digits change.

  Written for Arduino Mega and Arduino Uno
  Arduino IDE version 1.8.19
  
 Schematic and breadboard layout apply to Arduino Mega version.
  
  ### Connections between Arduino and TIL311:
  
| Arduino Mega Pin | Arduino Uno Pin | ATMega2560 Port | ATMega328P Port | TIL311 Pin No          | TIL311 Pin Function |
|------------------|-----------------|-----------------|-----------------|------------------------|---------------------|
| 22               | 8               | PA0             | PB0             | 3                      | Data A              |
| 23               | 9               | PA1             | PB1             | 2                      | Data B              |
| 24               | 10              | PA2             | PB2             | 13                     | Data C              |
| 25               | 11              | PA3             | PB3             | 12                     | Data D              |
| 26               | 5               | PA4             | PD5             | 4 (Via 680r resistor)  | Left Decimal Point  |
| 27               | 6               | PA5             | PD6             | 10 (Via 680r resistor) | Right Decimal Point |
| 28               | 7               | PA6             | PD7             | 5                      | Strobe              |
| 4                | 3               | N/A             | N/A             | 8                      | Blanking            |

| TIL311 connections:                                           |
|---------------------------------------------------------------|
| Pin 1 to +5v (LED Power Supply)                               |
| Pin 7 to GND (Common Ground)                                  |
| Pin 14 to +5v (Logic Power Supply)                            |
