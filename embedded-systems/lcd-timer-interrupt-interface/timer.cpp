// Author: Barack A. Marwanga
// Date: 9/27/2026
// Assignment: Lab 3
//----------------------------------------------------------------------//

#include "timer.h"
//You may use any timer you wish for the microsecond delay and the millisecond delay


/* Initialize timer 1, you should not turn the timer on here. Using CTC mode  .*/
void initTimer1(){
  TCCR1A = 0;
  TCCR1B = (1 << WGM12); // CTC mode 4, timer stopped (CS1[2:0] = 000)
  OCR1A = 15;            // 16 ticks at 16 MHz = 1 us
}

/* This delays the program an amount of microseconds specified by unsigned int delay.
*/
void delayUs(unsigned int delay){
  unsigned int i;
  for (i = 0; i < delay; i++) {
    TCNT1 = 0;
    TCCR1B |= (1 << CS10);                 // start, prescaler 1
    while (!(TIFR1 & (1 << OCF1A)));       // wait for compare match
    TIFR1 |= (1 << OCF1A);                 // clear flag
    TCCR1B &= ~(1 << CS10);                // stop timer
  }
}

/* Initialize timer 0, you should not turn the timer on here.
* You will need to use CTC mode */
void initTimer0(){
  TCCR0A = (1 << WGM01); // CTC mode
  TCCR0B = 0;            // timer stopped
  OCR0A = 249;           // 250 ticks with prescaler 64 at 16 MHz = 1 ms
}

/* This delays the program an amount specified by unsigned int delay.
* Use timer 0. Keep in mind that we need to choose our prescalar wisely
* such that our timer is precise to 1 millisecond and can be used for
* 100-2000 milliseconds
*/
void delayMs(unsigned int delay){
  unsigned int i;
  for (i = 0; i < delay; i++) {
    TCNT0 = 0;
    TCCR0B |= (1 << CS01) | (1 << CS00);   // start, prescaler 64
    while (!(TIFR0 & (1 << OCF0A)));
    TIFR0 |= (1 << OCF0A);
    TCCR0B &= ~((1 << CS01) | (1 << CS00)); // stop timer
  }
}
