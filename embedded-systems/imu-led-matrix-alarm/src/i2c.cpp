// Author: Barack A. Marwanga
// Net ID: 23862638
// Date: 11/9/2026
// Assignment: Lab 5
// File: i2c.cpp
// Description: Hardware TWI (I2C) master, 100 kHz, prescaler 1.
//
// Wiring (Arduino Mega 2560):
//   PD1 / D20  SDA  -> MPU-6050 SDA
//   PD0 / D21  SCL  -> MPU-6050 SCL
// The GY-521 board already has pull-ups on SDA and SCL. Tie AD0 to GND
// so the 7-bit address is 0x68, which is also the WHO_AM_I reset value.
//----------------------------------------------------------------------//

#include "i2c.h"

#include <avr/io.h>

#define I2C_TWBR 72
#define TWI_STATUS_MASK 0xF8
#define TWI_IDLE 0xF8

void InitI2C(void) {
  PRR0 &= ~(1 << PRTWI);
  TWSR &= ~((1 << TWPS1) | (1 << TWPS0));
  TWBR = I2C_TWBR;
  TWCR = (1 << TWEN);
}

void StartI2C_Trans(unsigned char SLA) {
  TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT))) {
  }

  TWDR = (unsigned char)(SLA << 1);
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT))) {
  }
}

void StopI2C_Trans(void) {
  if ((TWSR & TWI_STATUS_MASK) == TWI_IDLE) {
    return;
  }

  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
  while (TWCR & (1 << TWSTO)) {
  }
}

void Write(unsigned char data) {
  TWDR = data;
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT))) {
  }
}

void Read_from(unsigned char SLA, unsigned char MEMADDRESS) {
  StartI2C_Trans(SLA);
  Write(MEMADDRESS);

  TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT))) {
  }

  TWDR = (unsigned char)((SLA << 1) | 0x01);
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
  while (!(TWCR & (1 << TWINT))) {
  }

  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT))) {
  }

  StopI2C_Trans();
}

unsigned char Read_data(void) {
  return TWDR;
}
