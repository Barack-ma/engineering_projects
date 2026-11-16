// Author: Barack A. Marwanga
// Net ID: 23862638
// Date: 10/30/2026
// Assignment: Lab 4
// File: timer.h
// Description: Timer module header.
//----------------------------------------------------------------------//

#ifndef LAB4_TIMER_H
#define LAB4_TIMER_H

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

void initTimer0(void);
void delayMs(unsigned int delay);
void initTimer1(void);
void startTimer1(void);
void stopTimer1(void);
bool secondElapsed(void);

#endif /* LAB4_TIMER_H */
