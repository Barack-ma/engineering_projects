// Author: Barack A. Marwanga
// Date: 9/27/2026
// Assignment:     Lab 3
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
//----------------------------------------------------------------------//


#include <avr/io.h>
#include <avr/interrupt.h>
#include "led.h"
#include "switch.h"
#include "timer.h"
#include "lcd.h"

// defines
#define FAST_MS 100
#define SLOW_MS 200

/*
 * Defining a set of states that can be used in the state machine using an enum.
 */
typedef enum {
  waitPress,
  debouncePress,
  waitRelease,
  debounceRelease
} buttonState_t;

typedef enum {
  FAST,
  SLOW
} speedState_t;

// Initialize states.  Remember to use volatile
volatile buttonState_t buttonState = waitPress;
volatile speedState_t speedState = FAST;



int main(){

  initTimer0();
  initTimer1();
  initLCD();
  initSwitchPB3();
  initLED();
  sei(); // Enable global interrupts.
  moveCursor(0, 0); // moves the cursor to 0,0 position
  writeString("Current mode: ");
  moveCursor(1, 0);  // moves the cursor to 1,0 position
  writeString("Fast");

  unsigned char count = 0;

  while (1) {
    turnOnLEDWithChar(count);
    if (speedState == FAST) {
      delayMs(FAST_MS);
    }
    else {
      delayMs(SLOW_MS);
    }
    count = (count + 1) & 0x0F;

    switch (buttonState) {
      case debouncePress:
        delayMs(1);
        buttonState = waitRelease;
        break;
      case debounceRelease:
        delayMs(1);
        if (speedState == FAST) {
          speedState = SLOW;
          moveCursor(1, 0);
          writeString("Slow");
        }
        else {
          speedState = FAST;
          moveCursor(1, 0);
          writeString("Fast");
        }
        buttonState = waitPress;
        break;
      default:
        break;
    }
  }

  return 0;
}

/* Implement an Pin Change Interrupt which handles the switch being
* pressed and released. When the switch is pressed and released, the LEDs
* change at twice the original rate. If the LEDs are already changing at twice
* the original rate, it goes back to the original rate.
*/
ISR(PCINT0_vect){
  if (buttonState == waitPress) {
    buttonState = debouncePress;
  }
  else if (buttonState == waitRelease) {
    buttonState = debounceRelease;
  }
}
