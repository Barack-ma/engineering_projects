// Author: Barack A. Marwanga
// Net ID: 23862638
// Date: 10/30/2026
// Assignment: Lab 4
// File: shift_register.h
// Description: Shift-register module for the extra-credit display interface.
//----------------------------------------------------------------------//

#ifndef LAB4_SHIFT_REGISTER_H
#define LAB4_SHIFT_REGISTER_H

#include <avr/io.h>
#include <stdint.h>

void initShiftRegister(void);
void shiftRegisterWrite(uint8_t data);

#endif /* LAB4_SHIFT_REGISTER_H */
