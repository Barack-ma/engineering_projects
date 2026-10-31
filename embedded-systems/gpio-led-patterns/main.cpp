// Author: Barack A Marwanga
// Date: 9/10/2026
// Assignment:     Lab 1
//----------------------------------------------------------------------//

#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "switch.h"

// _delay_ms() requires a compile-time constant argument.
#define SHORT_DELAY 100   // 100 ms when the switch is not pressed
#define LONG_DELAY  1000  // 1000 ms (10x slower) when the switch is pressed

int main(){
  initLED();
  initSwitch();

  unsigned int led = 0;  // pair index: 0 = outer, 3 = inner
  int direction = 1;     // +1 moves inward, -1 moves outward

  while(1){
    runLED(led);

    // Pin 22 (PA0) is pulled high; pressed switch connects it to GND.
    if (PINA & (1 << PINA0)) {
      _delay_ms(SHORT_DELAY);  // switch not pressed
    }
    else {
      _delay_ms(LONG_DELAY);   // switch pressed: 1/10th the rate
    }

    // Bounce the pair index: 0,1,2,3,2,1,0,...
    if (led == 0) {
      direction = 1;
    }
    else if (led == 3) {
      direction = -1;
    }
    led = (unsigned int)((int)led + direction);
  }

  return 0;
}
