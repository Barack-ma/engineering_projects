// Author: Barack A. Marwanga
// Net ID: 23862638
// Date: 10/30/2026
// Assignment: Lab 4
// File: switch.h
// Description: Switch module header. External interrupt INT0 on PD0.
//----------------------------------------------------------------------//

#ifndef LAB4_SWITCH_H
#define LAB4_SWITCH_H

#include <avr/io.h>
#include <stdbool.h>

void initSwitchPD0(void);
void enableSwitchInterrupt(void);
void disableSwitchInterrupt(void);
bool isSwitchPressed(void);

#endif /* LAB4_SWITCH_H */
