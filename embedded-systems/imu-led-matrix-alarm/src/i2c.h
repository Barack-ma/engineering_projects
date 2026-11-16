// Author: Barack A. Marwanga
// Net ID: 23862638
// Date: 11/9/2026
// Assignment: Lab 5
// File: i2c.h
// Description: TWI master on the ATmega2560. The slave address passed to
//              these functions is the 7-bit address. The R/W bit is added
//              inside the functions.
//----------------------------------------------------------------------//

#ifndef LAB5_I2C_H
#define LAB5_I2C_H

void InitI2C(void);
void StartI2C_Trans(unsigned char SLA);
void StopI2C_Trans(void);
void Write(unsigned char data);
void Read_from(unsigned char SLA, unsigned char MEMADDRESS);
unsigned char Read_data(void);

#endif /* LAB5_I2C_H */
