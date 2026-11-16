// Author: Barack A. Marwanga
// Net ID: 23862638
// Date: 11/9/2026
// Assignment: Lab 5
// File: main.cpp
// Description: Read the MPU-6050 accelerometer over I2C and print X, Y, Z.
//              Below about 45 degrees from flat, the MAX7219 matrix shows a
//              smiley. Past that tilt it shows a frowny and a piezo chirp
//              starts. The chirp stays on after the board is set back down
//              until the button on D19 is pressed.
//----------------------------------------------------------------------//

#include <Arduino.h>
#include <avr/interrupt.h>
#include <stdint.h>

#include "i2c.h"
#include "pwm.h"
#include "spi.h"
#include "switch.h"
#include "timer.h"

#define MPU_SLA 0x68
#define PWR_MGMT_1 0x6B
#define WHO_AM_I 0x75
#define ACCEL_XOUT_H 0x3B
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40

#define TILT_Y_ENTER 12000
#define TILT_Z_ENTER 11000
#define TILT_Y_EXIT 9000
#define TILT_Z_EXIT 13000
#define DEBOUNCE_MS 50

typedef enum {
  WAIT_PRESS,
  DEBOUNCE_PRESS,
  WAIT_RELEASE,
  DEBOUNCE_RELEASE
} buttonState_t;

typedef enum {
  SHOW_SMILEY,
  SHOW_FROWNY
} faceState_t;

volatile buttonState_t buttonState = WAIT_PRESS;
volatile faceState_t faceState = SHOW_SMILEY;

static int16_t combineAccel(unsigned char high, unsigned char low) {
  return (int16_t)((((uint16_t)high) << 8) | low);
}

static uint16_t magnitude(int16_t value) {
  int32_t wide = value;
  if (wide < 0) {
    wide = -wide;
  }
  return (uint16_t)wide;
}

static bool tiltExceeded(int16_t yAccel, int16_t zAccel) {
  return (magnitude(yAccel) > TILT_Y_ENTER) || (magnitude(zAccel) < TILT_Z_ENTER);
}

static bool tiltCleared(int16_t yAccel, int16_t zAccel) {
  return (magnitude(yAccel) < TILT_Y_EXIT) && (magnitude(zAccel) > TILT_Z_EXIT);
}

int main(void) {
  init();
  Serial.begin(9600);

  initPWM();
  initTimer1();
  initSPI();
  initSwitchPD2();
  InitI2C();
  sei();

  showSmiley();

  Serial.println("Lab 5");
  Serial.println("Waking MPU-6050");

  StartI2C_Trans(MPU_SLA);
  Write(PWR_MGMT_1);
  Write(0x00);
  StopI2C_Trans();
  delayMs(100);

  Read_from(MPU_SLA, WHO_AM_I);
  Serial.print("WHO_AM_I: 0x");
  Serial.println(Read_data(), HEX);

  while (1) {
    unsigned char xHigh;
    unsigned char xLow;
    unsigned char yHigh;
    unsigned char yLow;
    unsigned char zHigh;
    unsigned char zLow;
    int16_t xAccel;
    int16_t yAccel;
    int16_t zAccel;

    Read_from(MPU_SLA, ACCEL_XOUT_H);
    xHigh = Read_data();
    Read_from(MPU_SLA, ACCEL_XOUT_L);
    xLow = Read_data();

    Read_from(MPU_SLA, ACCEL_YOUT_H);
    yHigh = Read_data();
    Read_from(MPU_SLA, ACCEL_YOUT_L);
    yLow = Read_data();

    Read_from(MPU_SLA, ACCEL_ZOUT_H);
    zHigh = Read_data();
    Read_from(MPU_SLA, ACCEL_ZOUT_L);
    zLow = Read_data();

    xAccel = combineAccel(xHigh, xLow);
    yAccel = combineAccel(yHigh, yLow);
    zAccel = combineAccel(zHigh, zLow);

    Serial.print("X: ");
    Serial.print((int)xAccel);
    Serial.print("\tY: ");
    Serial.print((int)yAccel);
    Serial.print("\tZ: ");
    Serial.println((int)zAccel);

    StopI2C_Trans();

    switch (faceState) {
      case SHOW_SMILEY:
        if (tiltExceeded(yAccel, zAccel)) {
          showFrowny();
          startAlarm();
          faceState = SHOW_FROWNY;
        }
        break;

      case SHOW_FROWNY:
        if (tiltCleared(yAccel, zAccel)) {
          showSmiley();
          faceState = SHOW_SMILEY;
        }
        break;

      default:
        faceState = SHOW_SMILEY;
        showSmiley();
        break;
    }

    switch (buttonState) {
      case WAIT_PRESS:
        break;

      case DEBOUNCE_PRESS:
        delayMs(DEBOUNCE_MS);
        if (isSwitchPressed()) {
          stopAlarm();
          Serial.println("alarm silenced");
          buttonState = WAIT_RELEASE;
        } else {
          buttonState = WAIT_PRESS;
        }
        break;

      case WAIT_RELEASE:
        break;

      case DEBOUNCE_RELEASE:
        delayMs(DEBOUNCE_MS);
        buttonState = WAIT_PRESS;
        break;

      default:
        buttonState = WAIT_PRESS;
        break;
    }
  }

  return 0;
}

ISR(INT2_vect) {
  if (buttonState == WAIT_PRESS) {
    buttonState = DEBOUNCE_PRESS;
  } else if (buttonState == WAIT_RELEASE) {
    buttonState = DEBOUNCE_RELEASE;
  }
}
