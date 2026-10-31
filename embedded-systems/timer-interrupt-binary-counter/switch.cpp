// Author: Barack A Marwanga
// Date: 9/14/2026
// Assignment:     Lab 2
//
// Description: This file implements the initialization of an external
// switch on PB3 (Arduino Mega pin 50) with a pin-change interrupt.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode.
 * Also enables pin-change interrupts for PB3 (PCINT3).
 *
 * Wiring: one side of the switch to pin 50 (PB3), the other side to GND.
 * Internal pull-up holds the pin HIGH when the switch is open - pressing
 * the switch pulls it LOW. PCINT0 covers PORTB pins PCINT0-PCINT7.
 */
void initSwitchPB3(){
  DDRB &= ~(1 << DDB3);       // PB3 as input
  PORTB |= (1 << PORTB3);     // enable internal pull-up on PB3

  PCICR |= (1 << PCIE0);      // enable pin-change interrupt group PCINT0-7
  PCMSK0 |= (1 << PCINT3);    // enable pin-change interrupt for PB3
}
