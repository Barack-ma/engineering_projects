# Lab 2 — Timer and Interrupt Binary Counter

**ECE 372A · Individual project · AVR C++ · Arduino Mega 2560 (ATmega2560)**

A four-bit counter displays values 0–15 on LEDs connected to PA0–PA3 (Mega pins 22–25). Timer0 in CTC mode provides nominal 1 ms tick delays. A switch on PB3 (Mega pin 50), configured using a pull-up and pin-change interrupt, toggles nominal 100 ms / 200 ms count rates through a debounce state machine.

## Modules

- `main.cpp`: counter and debounce state machine, `PCINT0_vect` interrupt service routine
- `led.cpp/.h`: output register configuration and four-bit masking
- `timer.cpp/.h`: Timer0 register setup and compare-match polling
- `switch.cpp/.h`: PB3 input and pin-change interrupt initialization

## Build

Use PlatformIO target `megaatmega2560` and the Arduino framework:

```sh
python -m pip install platformio
pio run
pio run --target upload
```

**Source publication is in progress.** A complete build requires the project `platformio.ini` and all `src/` files.

## Verification

Nominal rates are code-derived, not independently measured. Debounce latency is influenced by the blocking timing loop; hardware verification has not been reproduced.
