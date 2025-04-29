# ATMega328p_TC1_WGM5
<p>Arduino Nano fast PWM implementation</p>
<br></br>
<p>Generates a fast-pwm signal on pin D9, 50% duty cycle, 243KHz (nominal 244.144KHz), as provided hereby.</p>
<p>Leverages direct MCU register manipulation to adjust PWM waveform in frequency and duty-cycle.</p>
<p>Adjust duty cycle with OCR1A.</p>
<p>Adjust frequency with ICR1.</p>
<p>Extends functionality on comparator detection via ISR TIMER1_COMPA vector.</p>
<p>Leverages Timer/Counter1 register to offer best hardware MCU resolution of 16bit.</p>
<br></br>
![IMG_20250429_132206-a](https://github.com/user-attachments/assets/11b80d97-3cb2-4ddf-8716-7b2bfd8ed8ff)
<br></br>
<p>By: Javier.</p>
<p>Portfolio: https://sites.google.com/view/b-eng-jarl/home</p>
<p>Arduino Forums: j4v13r_987</p>
<p>GitHub: J4v1987</p>
<br></br>
<p>Further reading:</p>
  <p>FR1. Atmel (2015). ATmega328P 8-bit AVR Microcontroller with 32K Bytes In-System Programmable Flash DATASHEET. [online] Available at: https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf.</p>
<br></br>
<p>Acknowledgements:</p>
  <p>ACK1. Harvard-style references: MyBib Contributors (2019). Harvard Referencing Generator – FREE – (updated for 2019). [online] MyBib. Available at: https://www.mybib.com/tools/harvard-referencing-generator.</p>
  <p>ACK2. Peer-checking and internet data scraping: Pi.ai. (2025). AVR PWM [thread]. Pi, your personal AI. [online] Available at: https://pi.ai.</p>
<br></br>
<p>Discussions:</p>
  <p>DS1. Arduino Forum. (2025). Is the Timer/Counter 0 limited to prescaler of 64? [online] Available at: https://forum.arduino.cc/t/is-the-timer-counter-0-limited-to-prescaler-of-64/1376889?u=j4v13r_987 [Accessed 29 Apr. 2025].</p>
  <p>DS2. Dylan144GT (2018). Setting up Arduino Uno (ATMEGA328P) PWM with Timer1. [online] Stack Overflow. Available at: https://stackoverflow.com/questions/48873501/setting-up-arduino-uno-atmega328p-pwm-with-timer1.</p>
