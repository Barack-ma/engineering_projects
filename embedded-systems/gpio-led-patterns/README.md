# GPIO LED Patterns and Button-Controlled Timing

**University of Arizona · ECE 372A · Individual lab 1 · AVR C++ · ATmega2560 / Arduino Mega 2560**

## Overview

Eight LEDs on Arduino Mega 2560 pins 4–11 are driven directly via AVR GPIO registers. A switch on pin 22 (PA0) changes the delay between outward/inward moving LED pairs.

## Skills demonstrated

GPIO direction registers, bit manipulation, switch pull-up, delay-based scheduling. This implementation uses AVR registers directly rather than Arduino's high-level GPIO APIs.

## Hardware connections

LEDs: pins 4–11; switch: pin 22 (PA0) to ground; external LEDs need series resistors.

## Build and flash

This project uses PlatformIO with `board = megaatmega2560` and the Arduino framework for startup/toolchain integration. Source code uses AVR peripheral headers.

```bash
python -m pip install platformio
pio run
pio run --target upload
```

Run these commands from this project's directory. Upload requires a connected Arduino Mega 2560 and a correctly selected serial port.

## Source layout

- `src/main.cpp` — application behavior and initialization
- `src/led.cpp` / `src/led.h` — LED output configuration and control
- `src/switch.cpp` / `src/switch.h` — switch input configuration
- `platformio.ini` — PlatformIO target configuration

## Implementation notes

**Lab 1:** The LED animation uses blocking `_delay_ms` calls; speed is read each cycle.

## Verification and limitations

The submitted source tree contained a generated firmware build, but **I have not independently rebuilt or hardware-tested this cleaned portfolio copy**. This repository currently contains source code and setup information rather than oscilloscope captures, test reports, or demo photos. Add verified outcomes or hardware evidence when available.

## Attribution

Uploaded as an individual ECE 372A lab implementation. University assignment handouts, provided datasheets, personal student identifiers, and generated build artifacts are intentionally excluded. Code comments may retain assignment-oriented guidance from the supplied starter project.
