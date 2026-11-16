// Author: Barack A. Marwanga
// Net ID: 23862638
// Date: 11/9/2026
// Assignment: Lab 5
// File: switch.cpp
// Description: External interrupt INT2 on PD2, any logical change.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>

void initSwitchPD2(void) {
  DDRD &= ~(1 << DDD2);
  PORTD |= (1 << PORTD2);

  EICRA = (EICRA & ~((1 << ISC21) | (1 << ISC20))) | (1 << ISC20);
  EIFR |= (1 << INTF2);
  EIMSK |= (1 << INT2);
}

bool isSwitchPressed(void) {
  return (PIND & (1 << PIND2)) == 0;
}
