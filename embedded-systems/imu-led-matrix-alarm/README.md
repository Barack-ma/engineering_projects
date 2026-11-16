# Lab 5 — IMU Tilt Alarm and LED Matrix

ATmega2560 / Arduino Mega 2560 project for ECE 372A.

The system reads an MPU-6050 accelerometer over I²C, displays a smiley or frowny face on a MAX7219-driven 8×8 LED matrix over SPI, and sounds a passive-piezo chirp when the board exceeds the configured tilt threshold. The alarm remains latched until the pushbutton is pressed.

## Hardware

- Arduino Mega 2560 / ATmega2560
- GY-521 / MPU-6050 accelerometer
- MAX7219 8×8 LED matrix
- Passive piezo buzzer
- Pushbutton

## Interfaces

- I²C/TWI: MPU-6050 on D20/D21
- SPI: MAX7219 on D51/D52/D53
- Timer 3: piezo frequency generation on OC3A / D5
- Timer 1: 1 ms system tick and debounce timing
- INT2 / D19: active-low alarm-silence pushbutton
- Serial: 9600 baud accelerometer/debug output

## Build and upload

Open this folder as a PlatformIO project.

```bash
pio run
pio run -t upload
pio device monitor
```

The serial monitor is configured for 9600 baud.
