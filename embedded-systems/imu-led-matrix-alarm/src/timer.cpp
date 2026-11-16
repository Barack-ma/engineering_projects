// Author: Barack A. Marwanga
// Net ID: 23862638
// Date: 11/9/2026
// Assignment: Lab 5
// File: timer.cpp
// Description: Timer 1, CTC, 1 ms tick.
//----------------------------------------------------------------------//

#include "timer.h"
#include "pwm.h"

#include <avr/interrupt.h>
#include <avr/io.h>

static volatile unsigned long milliseconds = 0;

static unsigned long nowMs(void) {
  unsigned long now;
  unsigned char sreg = SREG;

  cli();
  now = milliseconds;
  SREG = sreg;
  return now;
}

void initTimer1(void) {
  TCCR1A = 0;
  TCCR1B = (1 << WGM12);
  OCR1A = 249;
  TCNT1 = 0;
  TIFR1 |= (1 << OCF1A);
  TIMSK1 |= (1 << OCIE1A);
  TCCR1B |= (1 << CS11) | (1 << CS10);
}

void delayMs(unsigned int delay) {
  unsigned long start = nowMs();

  while ((nowMs() - start) < delay) {
  }
}

ISR(TIMER1_COMPA_vect) {
  milliseconds++;
  serviceAlarm();
}
