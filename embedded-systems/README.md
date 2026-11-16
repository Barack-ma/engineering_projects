# ECE 372A — Embedded Systems Lab Portfolio

Four individual labs targeting the ATmega2560 (Arduino Mega 2560), demonstrating progressive development from direct GPIO manipulation to timers, interrupts, peripheral interfaces, ADC sampling and PWM motor control.

| Lab | Focus | Core skills |
| --- | --- | --- |
| [Lab 1 — GPIO LED patterns](gpio-led-patterns/) | Switch-controlled LED animation | AVR GPIO registers, masking, pull-up input |
| [Lab 2 — Timer and interrupt binary counter](timer-interrupt-binary-counter/) | LED binary count, mode switching | Timer0 CTC, pin-change ISR, debounce state machine |
| [Lab 3 — LCD interface](lcd-timer-interrupt-interface/) | LCD mode display and binary counter | HD44780 4-bit interface, Timer0/Timer1, ISR |
| [Lab 4 — ADC/PWM motor control](adc-pwm-motor-control/) | Potentiometer-controlled bidirectional DC motor with timed stop/countdown | 10-bit ADC, Timer3 Fast PWM, L293D H-bridge, INT0, Timer0/Timer1, 74HC595 |

Each project includes its own PlatformIO configuration and source files.
