// Author: Barack A Marwanga
// Date: 9/14/2026
// Assignment:     Lab 2
//
// Description: This file implements functions that utilize Timer 0 in CTC
// mode to produce a precise millisecond delay.
//----------------------------------------------------------------------//

#include "timer.h"

/* Initialize timer 0, one should not turn the timer on here.
 * I will need to use CTC mode
 *
 * 16 MHz clock, 8-bit Timer 0.
 * CTC with OCR0A = 249 and a later prescaler of 64 gives:
 *   T = (OCR0A + 1) * prescaler / F_CPU
 *     = 250 * 64 / 16e6 = 1.000 ms
 */
void initTimer0(){
  // WGM02:0 = 010 -> CTC mode, TOP = OCR0A
  TCCR0A &= ~(1 << WGM00);
  TCCR0A |= (1 << WGM01);
  TCCR0B &= ~(1 << WGM02);

  OCR0A = 249;  // compare match every 250 ticks once the timer is started
}

/* This delays the program an amount specified by unsigned int delay.
 * Use timer 0. Keep in mind that I will need to choose your prescalar wisely
 * such that the timer is precise to 1 millisecond and can be used for
 * 100-200 milliseconds
 *
 * Starts Timer 0 with prescaler 64, waits for OCF0A once per millisecond,
 * then turns the timer off. Works for delays of at least 100-200 ms.
 */
void delayMs(unsigned int delay){
  unsigned int i;

  // CS02:0 = 011 -> clk/64. Do not start the clock in initTimer0().
  TCCR0B &= ~(1 << CS02);
  TCCR0B |= (1 << CS01) | (1 << CS00);

  for (i = 0; i < delay; i++) {
    TCNT0 = 0;                  // start each millisecond from 0
    TIFR0 |= (1 << OCF0A);      // clear the CTC flag (write 1 to TIFR0)
    while (!(TIFR0 & (1 << OCF0A))) {
      // wait until Timer 0 matches OCR0A (1 ms)
    }
  }

  // Stop the timer so it does not keep running between delays.
  TCCR0B &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
}
