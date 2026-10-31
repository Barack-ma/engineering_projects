# Lab 3 — HD44780 LCD, Timers and Interrupts

**ECE 372A · Individual project · AVR C++ · Arduino Mega 2560 (ATmega2560)**

An LCD-enhanced four-bit LED counter. A direct-register LCD driver sends HD44780 commands in 4-bit mode. Timer0 and Timer1 provide millisecond and microsecond delay routines; pin-change interrupts handle a speed-mode switch.

## Hardware interface

- LCD DB4–DB7: PA0–PA3; RS: PA6; E: PA7
- Four binary LEDs: PD0–PD3
- Mode-switch input: PB3

Check the full physical schematic, power, LCD contrast and peripheral wiring before connecting hardware.

## Source organization

- `main.cpp` — mode state machine, 4-bit counter and interrupt handler
- `lcd.cpp/.h` — initialization, commands, character/string output
- `timer.cpp/.h` — Timer0 and Timer1 delay helpers
- `led.cpp/.h` — binary LED outputs
- `switch.cpp/.h` — pin-change input setup

## Build

Use PlatformIO with `board = megaatmega2560`:

```sh
python -m pip install platformio
pio run
pio run --target upload
```

**Source publication is in progress.** Build requires the project `platformio.ini` and complete `src/` directory.

## Verification

Code review confirms LCD signaling and timer routines exist; no independently verified hardware test, oscilloscope trace, or measured timing result is claimed.
