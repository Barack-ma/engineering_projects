// Author: Barack A. Marwanga
// Net ID: 23862638
// Date: 10/30/2026
// Assignment: Lab 4
// File: shift_register.c
// Description: Bit-banged serial load of the SN74HC595.
//
// Extra credit wiring (Arduino Mega 2560). PORTC is not used.
//   PA2 / D24 -> 74HC595 pin 14 (SER)
//   PA3 / D25 -> 74HC595 pin 11 (SRCLK)
//   PA4 / D26 -> 74HC595 pin 12 (RCLK)
//   74HC595 pin 13 (OE)    -> GND
//   74HC595 pin 10 (SRCLR) -> 5 V
//   74HC595 pin 16 -> 5 V, pin 8 -> GND
//----------------------------------------------------------------------//

#include "shift_register.h"

#define SER_PIN   PA2
#define SRCLK_PIN PA3
#define RCLK_PIN  PA4

void initShiftRegister(void) {
  DDRA |= (1 << SER_PIN) | (1 << SRCLK_PIN) | (1 << RCLK_PIN);
  PORTA &= ~((1 << SER_PIN) | (1 << SRCLK_PIN) | (1 << RCLK_PIN));
}

void shiftRegisterWrite(uint8_t data) {
  uint8_t bit;

  for (bit = 0; bit < 8; bit++) {
    if (data & 0x80) PORTA |= (1 << SER_PIN);
    else PORTA &= ~(1 << SER_PIN);

    PORTA |= (1 << SRCLK_PIN);
    PORTA &= ~(1 << SRCLK_PIN);
    data <<= 1;
  }

  PORTA |= (1 << RCLK_PIN);
  PORTA &= ~(1 << RCLK_PIN);
}
