// Author: Barack A Marwanga      
// Date: 9/10/2026          
// Assignment:     Lab 1
//----------------------------------------------------------------------//
#ifndef LED_H
#define LED_H

// Initialize development-board pins 4-11 as LED outputs.
void initLED();

// Turn on only the LED connected to development-board pin 'led'.
void turnOnLED(unsigned int led);

// Turn off only the LED connected to development-board pin 'led'.
void turnOffLED(unsigned int led);

// Light LED pair 'led' (0 = outer pins 4 and 11, 3 = inner pins 7 and 8)
// and turn the previous neighboring pair off.
void runLED(unsigned int led);

#endif
