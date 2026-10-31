# HD44780 LCD Interface with Timers and Interrupts

**University of Arizona · ECE 372A · Individual lab 3 · AVR C++ · ATmega2560 / Arduino Mega 2560**

## Overview

Builds on the binary LED counter with a direct-register, 4-bit HD44780-compatible LCD driver and two timer peripherals: Timer0 for millisecond delays and Timer1 for microsecond delays. The LCD displays the selected mode.

## Skills demonstrated

4-bit LCD signaling, peripheral register control, timer compare-match polling, interrupt-driven input. This implementation uses AVR registers directly rather than Arduino's high-level GPIO APIs.

## Hardware connections

LCD data DB4–DB7: PA0–PA3; RS: PA6; E: PA7; switch: PB3; four binary LEDs: PD0–PD3. Consult the physical schematic before wiring.

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
- `src/lcd.cpp` / `src/lcd.h` — 4-bit LCD protocol and display utilities
- `platformio.ini` — PlatformIO target configuration

## Implementation notes

**Lab 3:** A software state machine and pin-change ISR select modes. Timer0/Timer1 timing is polling-based; LCD code implements HD44780 initialization and nibble transfers.

## Verification and limitations

The submitted source tree contained a generated firmware build, but **I have not independently rebuilt or hardware-tested this cleaned portfolio copy**. This repository currently contains source code and setup information rather than oscilloscope captures, test reports, or demo photos. Add verified outcomes or hardware evidence when available.

## Attribution

Uploaded as an individual ECE 372A lab implementation. University assignment handouts, provided datasheets, personal student identifiers, and generated build artifacts are intentionally excluded. Code comments may retain assignment-oriented guidance from the supplied starter project.
