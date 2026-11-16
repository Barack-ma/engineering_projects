// Author: Barack A. Marwanga
// Net ID: 23862638
// Date: 11/9/2026
// Assignment: Lab 5
// File: pwm.cpp
// Description: Timer 3 CTC, toggle OC3A. That is a 50% PWM square wave
//              whose frequency is set by OCR3A.
//----------------------------------------------------------------------//

#include "pwm.h"
#include <avr/io.h>

#define CHIRP_SLICE_MS 35

static const unsigned int CHIRP_OCR[] = {
    499, 399, 332, 285, 249, 0,
    499, 332, 249, 0, 0, 0, 0, 0
};

#define CHIRP_SLICES (sizeof(CHIRP_OCR) / sizeof(CHIRP_OCR[0]))

static volatile unsigned char alarmEnabled = 0;

static void driveTone(unsigned int ocr) {
  if (ocr == 0) {
    TCCR3A &= ~(1 << COM3A0);
    PORTE &= ~(1 << PE3);
    return;
  }

  OCR3A = ocr;
  TCNT3 = 0;
  TCCR3A |= (1 << COM3A0);
}

void initPWM(void) {
  DDRE |= (1 << DDE3);
  PORTE &= ~(1 << PE3);

  TCCR3A = 0;
  TCCR3B = (1 << WGM32);
  OCR3A = CHIRP_OCR[0];
  TCNT3 = 0;
  TCCR3B |= (1 << CS31);
  alarmEnabled = 0;
}

void startAlarm(void) {
  alarmEnabled = 1;
}

void stopAlarm(void) {
  alarmEnabled = 0;
}

void serviceAlarm(void) {
  static unsigned char slice = 0;
  static unsigned char elapsed = 0;
  static unsigned char running = 0;

  if (!alarmEnabled) {
    if (running) {
      driveTone(0);
      running = 0;
      slice = 0;
      elapsed = 0;
    }
    return;
  }

  if (!running) {
    running = 1;
    slice = 0;
    elapsed = 0;
    driveTone(CHIRP_OCR[0]);
    return;
  }

  elapsed++;
  if (elapsed < CHIRP_SLICE_MS) {
    return;
  }

  elapsed = 0;
  slice++;
  if (slice >= CHIRP_SLICES) {
    slice = 0;
  }
  driveTone(CHIRP_OCR[slice]);
}
