# Lab 1 — GPIO LED Patterns

**ECE 372A · Individual project · AVR C++ · Arduino Mega 2560 (ATmega2560)**

Eight LEDs on pins 4–11 run an inward/outward animation, with a switch on pin 22 (PA0) controlling timing. The implementation uses direct AVR I/O registers, direction masks, pull-ups, and blocking delays rather than high-level Arduino GPIO calls.

## Hardware

- Eight external LEDs with current-limiting resistors on Mega pins 4–11
- Switch between Mega pin 22 (PA0) and GND

## Build

PlatformIO target: `megaatmega2560` with Arduino framework.

```sh
python -m pip install platformio
pio run
pio run --target upload
```

Run from the project directory after checking wiring and upload serial port. **Source publication is in progress; these commands require `platformio.ini` and `src/` files.**

## Modules

`main.cpp` — application loop; `led.cpp/.h` — GPIO/LED patterns; `switch.cpp/.h` — switch input.

## Verification

Generated firmware existed in the original submission, but this GitHub version has not been independently rebuilt or tested on hardware. No performance measurements or test waveforms are claimed.
