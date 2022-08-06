# Arduino TIL311 Tester
An Arduino sketch for testing TIL311/DIS1417 display modules.

  Displays values 0 to F on the display.
  Blanking tested by applying PWM to the blanking pin.

  Written for Arduino Mega.
  Arduino IDE version 1.8.19
  
  #### Connections between Arduino and TIL311:
  
| Arduino Pin | TIL311 Pin |
|-------------|------------|
| 22 / PA0    | 3          |
| 23 / PA1    | 2          |
| 24 / PA2    | 13         |
| 25 / PA3    | 12         |
| 3           | 5          |
| 4           | 8          |

| TIL311 connections:                                           |
|---------------------------------------------------------------|
| Pin 1 to +5v (LED Power Supply)                               |
| Pin 4 to +5v via 680r resistor (Left decimal point cathode)   |
| Pin 7 to GND (Common Ground)                                  |
| Pin 10 to +5v via 680r resistor (Right decimal point cathode) |
| Pin 14 to +5v (Logic Power Supply)                            |
