# ECE 372A — Embedded Systems Lab Portfolio

Three individual labs targeting the ATmega2560 (Arduino Mega 2560), demonstrating progressive development from direct GPIO manipulation to timer peripherals, interrupt handling and an HD44780 LCD driver.

| Lab | Focus | Core skills |
| --- | --- | --- |
| [Lab 1 — GPIO LED patterns](gpio-led-patterns/) | Switch-controlled LED animation | AVR GPIO registers, masking, pull-up input |
| [Lab 2 — Timer and interrupt binary counter](timer-interrupt-binary-counter/) | LED binary count, mode switching | Timer0 CTC, pin-change ISR, debounce state machine |
| [Lab 3 — LCD interface](lcd-timer-interrupt-interface/) | LCD mode display and binary counter | HD44780 4-bit interface, Timer0/Timer1, ISR |

All three projects include their own PlatformIO configuration and source files. See each lab's README for wiring, build instructions, implementation notes, and current verification limitations.


