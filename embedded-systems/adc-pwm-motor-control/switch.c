// Author: Barack A. Marwanga
// Net ID: 23862638
// Date: 10/30/2026
// Assignment: Lab 4
// File: switch.c
// Description: Switch on PD0 using external interrupt INT0.
//----------------------------------------------------------------------//

#include "switch.h"

void initSwitchPD0(void) {
  DDRD &= ~(1 << DDD0);
  PORTD |= (1 << PORTD0);

  EICRA = (EICRA & ~((1 << ISC01) | (1 << ISC00))) | (1 << ISC00);
  EIFR |= (1 << INTF0);
  EIMSK |= (1 << INT0);
}

void enableSwitchInterrupt(void) {
  EIFR |= (1 << INTF0);
  EIMSK |= (1 << INT0);
}

void disableSwitchInterrupt(void) {
  EIMSK &= ~(1 << INT0);
  EIFR |= (1 << INTF0);
}

bool isSwitchPressed(void) {
  return (PIND & (1 << PIND0)) == 0;
}
