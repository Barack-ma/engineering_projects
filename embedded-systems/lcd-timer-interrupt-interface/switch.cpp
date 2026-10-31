// Description: This file implements the initialization of an external
// switch.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode
 */
void initSwitchPB3(){
  DDRB &= ~(1 << DDB3);      // PB3 as input
  PORTB |= (1 << PORTB3);    // enable pull-up
  PCICR |= (1 << PCIE0);     // pin-change interrupt for PCINT0-7 (PORTB)
  PCMSK0 |= (1 << PCINT3);   // enable interrupt on PB3 / PCINT3
}
