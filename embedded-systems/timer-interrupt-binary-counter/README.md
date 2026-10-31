# Timer0, Pin-Change Interrupts and Binary LED Counter

**University of Arizona · ECE 372A · Individual lab 2 · AVR C++ · ATmega2560 / Arduino Mega 2560**

## Overview

A four-bit binary counter displays values 0–15 on four LEDs. Timer0 in CTC mode supplies millisecond timing; a switch on PB3 uses a pin-change ISR and a debounced state machine to change between 100 ms and 200 ms nominal intervals.

## Skills demonstrated

Timer0 CTC configuration, interrupt service routines, debouncing state machines, bit masking. This implementation uses AVR registers directly rather than Arduino's high-level GPIO APIs.

## Hardware connections

LEDs: PA0–PA3 (Mega pins 22–25); switch: PB3 (Mega pin 50) to ground with internal pull-up.

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
- `src/timer.cpp` / `src/timer.h` — hardware timer initialization and delay helpers
- `platformio.ini` — PlatformIO target configuration

## Implementation notes

**Lab 2:** Timer0 polling is used for delays, and the ISR advances button state. Debounce and latency are influenced by the blocking delay loop.

## Verification and limitations

The submitted source tree contained a generated firmware build, but **I have not independently rebuilt or hardware-tested this cleaned portfolio copy**. This repository currently contains source code and setup information rather than oscilloscope captures, test reports, or demo photos. Add verified outcomes or hardware evidence when available.

## Attribution

Uploaded as an individual ECE 372A lab implementation. University assignment handouts, provided datasheets, personal student identifiers, and generated build artifacts are intentionally excluded. Code comments may retain assignment-oriented guidance from the supplied starter project.
