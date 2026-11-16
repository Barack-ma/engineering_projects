# ECE 372A — Embedded Systems Lab Portfolio

Five individual labs targeting the ATmega2560 (Arduino Mega 2560), demonstrating progressive development from direct GPIO manipulation to timers, interrupts, peripheral interfaces, ADC/PWM control, I²C and SPI sensor/display integration.

| Lab | Focus | Core skills |
| --- | --- | --- |
| [Lab 1 — GPIO LED patterns](gpio-led-patterns/) | Switch-controlled LED animation | AVR GPIO registers, masking, pull-up input |
| [Lab 2 — Timer and interrupt binary counter](timer-interrupt-binary-counter/) | LED binary count, mode switching | Timer0 CTC, pin-change ISR, debounce state machine |
| [Lab 3 — LCD interface](lcd-timer-interrupt-interface/) | LCD mode display and binary counter | HD44780 4-bit interface, Timer0/Timer1, ISR |
| [Lab 4 — ADC/PWM motor control](adc-pwm-motor-control/) | Potentiometer-controlled bidirectional DC motor with timed stop/countdown | 10-bit ADC, Timer3 Fast PWM, L293D H-bridge, INT0, Timer0/Timer1, 74HC595 |
| [Lab 5 — IMU tilt alarm](imu-led-matrix-alarm/) | Accelerometer tilt detection, LED-matrix status, latched piezo alarm | I²C/TWI, SPI, MPU-6050, MAX7219, Timer1/Timer3, INT2 |

Each project includes its own PlatformIO configuration and source files.
