// Author: Barack A Marwanga
// Date: 9/10/2026
// Assignment:     Lab 1
//----------------------------------------------------------------------//

#include <avr/io.h>
#include "switch.h"

// Arduino Mega pin 22 is PORTA0. The schematic ties the switch between
// pin 22 and GND, so the pin reads LOW when the switch is held down.

// Configure pin 22 as an input with the internal pull-up enabled.
void initSwitch(){
  DDRA &= ~(1 << DDA0);     // pin 22 as input
  PORTA |= (1 << PORTA0);   // enable pull-up (HIGH when not pressed)
}
