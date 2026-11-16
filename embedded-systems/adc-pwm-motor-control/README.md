# Lab 4 — ADC/PWM Motor Control

ATmega2560 project that controls DC motor speed and direction from a potentiometer and combines ADC sampling, Timer 3 PWM, an L293D H-bridge, external interrupts, timer-based debouncing/countdown logic, and a seven-segment display.

## Highlights
- 10-bit ADC on A0 (PF0/ADC0)
- Timer 3 Fast PWM on OC3A
- L293D bidirectional motor control
- INT0 pushbutton with Timer 0 debounce
- Timer 1 one-second countdown
- State-machine behavior for motor stop/countdown
- Extra-credit 74HC595 interface for the common-cathode seven-segment display

## Build
Open this directory as a PlatformIO project and use the included `platformio.ini` with an Arduino Mega 2560.
