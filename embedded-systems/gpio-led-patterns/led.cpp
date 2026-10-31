// Author: Barack A Marwanga
// Date:  9/10/2026
// Assignment:     Lab 1
//----------------------------------------------------------------------//
#include <avr/io.h>
#include "led.h"

// Arduino Mega 2560 pin-to-port map for this lab's LED schematic:
// Pin 4  -> PORTG5    Pin 5  -> PORTE3
// Pin 6  -> PORTH3    Pin 7  -> PORTH4
// Pin 8  -> PORTH5    Pin 9  -> PORTH6
// Pin 10 -> PORTB4    Pin 11 -> PORTB5
// LEDs are wired pin -> resistor -> LED anode, cathode -> GND (active high).

// Set pins 4-11 as outputs so they can drive the eight LEDs.
void initLED(){
  DDRG |= (1 << DDG5);   // pin 4
  DDRE |= (1 << DDE3);   // pin 5
  DDRH |= (1 << DDH3) | (1 << DDH4) | (1 << DDH5) | (1 << DDH6); // pins 6-9
  DDRB |= (1 << DDB4) | (1 << DDB5); // pins 10-11

  // Start with every LED off without touching unrelated port bits.
  PORTG &= ~(1 << PORTG5);
  PORTE &= ~(1 << PORTE3);
  PORTH &= ~((1 << PORTH3) | (1 << PORTH4) | (1 << PORTH5) | (1 << PORTH6));
  PORTB &= ~((1 << PORTB4) | (1 << PORTB5));
}

// Drive the LED on the given development-board pin HIGH. Other LEDs are unchanged.
void turnOnLED(unsigned int led){
  switch (led) {
    case 4:  PORTG |= (1 << PORTG5); break;
    case 5:  PORTE |= (1 << PORTE3); break;
    case 6:  PORTH |= (1 << PORTH3); break;
    case 7:  PORTH |= (1 << PORTH4); break;
    case 8:  PORTH |= (1 << PORTH5); break;
    case 9:  PORTH |= (1 << PORTH6); break;
    case 10: PORTB |= (1 << PORTB4); break;
    case 11: PORTB |= (1 << PORTB5); break;
    default: break;
  }
}

// Drive the LED on the given development-board pin LOW. Other LEDs are unchanged.
void turnOffLED(unsigned int led){
  switch (led) {
    case 4:  PORTG &= ~(1 << PORTG5); break;
    case 5:  PORTE &= ~(1 << PORTE3); break;
    case 6:  PORTH &= ~(1 << PORTH3); break;
    case 7:  PORTH &= ~(1 << PORTH4); break;
    case 8:  PORTH &= ~(1 << PORTH5); break;
    case 9:  PORTH &= ~(1 << PORTH6); break;
    case 10: PORTB &= ~(1 << PORTB4); break;
    case 11: PORTB &= ~(1 << PORTB5); break;
    default: break;
  }
}

// led is the pair index from the outside of the board inward:
//   0 -> pins 4 and 11 (outermost)
//   1 -> pins 5 and 10
//   2 -> pins 6 and 9
//   3 -> pins 7 and 8  (innermost)
// Turns the current pair on and the neighboring (previous) pair(s) off
// so only two LEDs are lit, whether the pattern is moving in or out.
void runLED(unsigned int led){
  unsigned int leftPin = 4 + led;     // 4, 5, 6, 7
  unsigned int rightPin = 11 - led;   // 11, 10, 9, 8

  // Turn off the pair one step outward (used when moving inward).
  if (led > 0) {
    turnOffLED(leftPin - 1);
    turnOffLED(rightPin + 1);
  }

  // Turn off the pair one step inward (used when moving outward).
  if (led < 3) {
    turnOffLED(leftPin + 1);
    turnOffLED(rightPin - 1);
  }

  turnOnLED(leftPin);
  turnOnLED(rightPin);
}
