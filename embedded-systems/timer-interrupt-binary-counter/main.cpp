// Author: Barack A Marwanga
// Date: 9/14/2026
// Assignment:     Lab 2
//
// Description: Four LEDs on PA0-PA3 count in binary from 0 to 15. Timer 0
// provides a 100 ms or 200 ms delay between counts. A switch on PB3 uses a
// pin-change ISR and a debounce state machine so that a press-and-release
// toggles the count rate between 200 ms (original) and 100 ms (twice as fast).
// This file does not write special-function registers except to read the
// switch pin if needed.
//----------------------------------------------------------------------//
#include <avr/io.h>
#include <avr/interrupt.h>
#include "led.h"
#include "switch.h"
#include "timer.h"

/*
 * Define a set of states that can be used in the state machine using an enum.
 *
 * wait_press / wait_release: stable switch levels.
 * debounce_press / debounce_release: short waits after an edge so bounce
 * does not look like extra presses.
 *
 * speedType selects the LED count period: 200 ms (slow) or 100 ms (fast).
 */
typedef enum stateType {
  wait_press,
  debounce_press,
  wait_release,
  debounce_release
} stateType;

typedef enum speedType {
  slow,  // original rate: 200 ms per count
  fast   // twice the original rate: 100 ms per count
} speedType;

volatile stateType state = wait_press;
volatile speedType speed = slow;

int main(){

  initLED();
  initSwitchPB3();
  initTimer0();
  sei();  // enable pin-change interrupts globally

  unsigned char count = 0;  // binary value shown on PA0-PA3, wraps at 15

  /*
   * Implement a state machine in the while loop which achieves the assignment
   * requirements.
   *
   * Each pass updates the LEDs, waits 100 or 200 ms depending on speed, then
   * advances the 4-bit count. Debounce states are handled in the same loop
   * after each blink so the ISR only requests a transition and the main
   * context performs the timed debounce.
   */
	while (1) {
    turnOnLEDWithChar(count);

    // Wait 200 ms (slow) or 100 ms (fast) in 1 ms steps so a press/release
    // during the blink delay is still seen by the debounce state machine.
    unsigned int blinkDelay = (speed == slow) ? 200 : 100;
    unsigned int t;
    for (t = 0; t < blinkDelay; t++) {
      delayMs(1);

      switch (state) {
        case wait_press:
          break;

        case debounce_press:
          delayMs(50);  // wait for the press bounce to settle
          state = wait_release;
          break;

        case wait_release:
          break;

        case debounce_release:
          delayMs(50);  // wait for the release bounce to settle
          // Rate changes only after a full press and release.
          if (speed == slow) {
            speed = fast;
          }
          else {
            speed = slow;
          }
          state = wait_press;
          break;
      }
    }

    count = (count + 1) & 0x0F;  // 0, 1, ..., 15, 0, ...
	}
  return 0;
}

/* Implement an Pin Change Interrupt which handles the switch being
 * pressed and released. When the switch is pressed and released, the LEDs
 * change at twice the original rate. If the LEDs are already changing at twice
 * the original rate, it goes back to the original rate.
 *
 * PCINT0_vect covers PORTB, including PB3. The ISR only advances the debounce
 * state machine; the rate is toggled in main after debounce_release.
 */
ISR(PCINT0_vect){
  if (state == wait_press) {
    state = debounce_press;
  }
  else if (state == wait_release) {
    state = debounce_release;
  }
}
