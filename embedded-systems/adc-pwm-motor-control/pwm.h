// Author: Barack A. Marwanga
// Net ID: 23862638
// Date: 10/30/2026
// Assignment: Lab 4
// File: pwm.h
// Description: PWM and motor-control module header.
//----------------------------------------------------------------------//

#ifndef LAB4_PWM_H
#define LAB4_PWM_H

#include <avr/io.h>
#include <stdint.h>

void initPWM(void);
void changeDutyCycle(uint16_t adcValue);
void turnMotorOff(void);

#endif /* LAB4_PWM_H */
