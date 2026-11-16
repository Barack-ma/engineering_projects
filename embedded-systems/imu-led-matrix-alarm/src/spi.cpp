// Author: Barack A. Marwanga
// Net ID: 23862638
// Date: 11/9/2026
// Assignment: Lab 5
// File: spi.cpp
// Description: MAX7219 (or MAX7221) on the hardware SPI port.
//----------------------------------------------------------------------//

#include "spi.h"
#include <avr/io.h>

#define MAX7219_NOOP 0x00
#define MAX7219_DIGIT0 0x01
#define MAX7219_DECODE 0x09
#define MAX7219_INTENSITY 0x0A
#define MAX7219_SCAN_LIMIT 0x0B
#define MAX7219_SHUTDOWN 0x0C
#define MAX7219_DISPLAY_TEST 0x0F

static const unsigned char SMILEY[8] = {
    0x3C, 0x42, 0xA5, 0x81, 0xA5, 0x99, 0x42, 0x3C
};

static const unsigned char FROWNY[8] = {
    0x3C, 0x42, 0xA5, 0x81, 0x99, 0xA5, 0x42, 0x3C
};

static void spiTransfer(unsigned char data) {
  SPDR = data;
  while (!(SPSR & (1 << SPIF))) {
  }
}

static void max7219Write(unsigned char reg, unsigned char value) {
  PORTB &= ~(1 << PB0);
  spiTransfer(reg);
  spiTransfer(value);
  PORTB |= (1 << PB0);
}

static void showPattern(const unsigned char pattern[8]) {
  unsigned char row;

  for (row = 0; row < 8; row++) {
    max7219Write((unsigned char)(MAX7219_DIGIT0 + row), pattern[row]);
  }
}

void initSPI(void) {
  DDRB |= (1 << DDB2) | (1 << DDB1) | (1 << DDB0);
  PORTB |= (1 << PB0);

  SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
  SPSR &= ~(1 << SPI2X);

  max7219Write(MAX7219_DISPLAY_TEST, 0x00);
  max7219Write(MAX7219_DECODE, 0x00);
  max7219Write(MAX7219_SCAN_LIMIT, 0x07);
  max7219Write(MAX7219_INTENSITY, 0x03);
  max7219Write(MAX7219_SHUTDOWN, 0x01);
  max7219Write(MAX7219_NOOP, 0x00);

  showPattern(SMILEY);
}

void showSmiley(void) {
  showPattern(SMILEY);
}

void showFrowny(void) {
  showPattern(FROWNY);
}
