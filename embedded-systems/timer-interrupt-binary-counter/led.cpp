// Author: Barack A Marwanga
// Date: 9/14/2026
// Assignment:     Lab 2
//
// Description: This file implements turnOnLEDWithChar and initLED to
// control four LEDs on PA0-PA3 as a 4-bit binary number (0-15).
//----------------------------------------------------------------------//


#include <avr/io.h>
#include "led.h"

/* Initialize PA0, PA1, PA2, and PA3 to outputs
 * Arduino Mega mapping: PA0=pin 22, PA1=pin 23, PA2=pin 24, PA3=pin 25.
 * LEDs are wired pin -> resistor -> LED anode, cathode -> GND (active high).
 */
void initLED(){
  DDRA |= (1 << DDA0) | (1 << DDA1) | (1 << DDA2) | (1 << DDA3);
  PORTA &= ~((1 << PORTA0) | (1 << PORTA1) | (1 << PORTA2) | (1 << PORTA3));
}

/* This must be one line of code.
 * In this function I will be giving a number "num" which will be represented
 * in binary by four LEDs. It must effectively assign the lowest four bits of
 * "num" to the appropriate bits of PORTA.
 *
 * Mask PA0-PA3 to 0, then OR in the low nibble of num. Upper bits of PORTA
 * are left unchanged.
 */
void turnOnLEDWithChar(unsigned char num){
  PORTA = (PORTA & 0xF0) | (num & 0x0F);
}
