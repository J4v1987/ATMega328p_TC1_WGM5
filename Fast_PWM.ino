/*
Arduino Nano fast PWM implementation

Generates a fast-pwm signal on pin D9, 50% duty cycle, 243KHz (nominal 244.144KHz), as provided hereby.
Adjust duty cycle with OCR1A.
Adjust frequency with ICR1.
Extends functionality on comparator detection via ISR TIMER1_COMPA vector.
Leverages Timer/Counter1 register to offer best hardware MCU resolution of 16bit.

By: Javier.
Portfolio: https://sites.google.com/view/b-eng-jarl/home
Arduino Forums: j4v13r_987
GitHub: J4v1987

History:
  H1. Loaded to Arduino Nano V3 using Arduino IDE 2.3.6. Deemed operational as per read-me photograph.

Further reading:
  FR1. Atmel (2015). ATmega328P 8-bit AVR Microcontroller with 32K Bytes In-System Programmable Flash DATASHEET. [online] Available at: https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf.

Acknowledgements:
  ACK1. Harvard-style references: MyBib Contributors (2019). Harvard Referencing Generator – FREE – (updated for 2019). [online] MyBib. Available at: https://www.mybib.com/tools/harvard-referencing-generator.
  ACK2. Peer-checking and internet data scrapping: Pi.ai. (2025). Pi, your personal AI. [online] Available at: https://pi.ai.

Discussions:
  DS1. Arduino Forum. (2025). Is the Timer/Counter 0 limited to prescaler of 64? [online] Available at: https://forum.arduino.cc/t/is-the-timer-counter-0-limited-to-prescaler-of-64/1376889?u=j4v13r_987 [Accessed 29 Apr. 2025].
  DS2. Dylan144GT (2018). Setting up Arduino Uno (ATMEGA328P) PWM with Timer1. [online] Stack Overflow. Available at: https://stackoverflow.com/questions/48873501/setting-up-arduino-uno-atmega328p-pwm-with-timer1.
*/

ISR(TIMER1_COMPA_vect)
{
  //Do nothing
}

void setup() {
  // Set pin D9 as output, tied to OC1A register.
  // FR1: sec. 13.3.1, figure 1-1. 
  DDRB = (1 << DDB1);

  // Reset the timer 1 register to assure initialization from zero.
  // FR1: sec. 15.2.1, figure 15-1, figure 15-7.
  TCNT1 = 0;
  
  // Set WGM mode 5, TOP compare at ICR1, toggle at OCR1A, no prescaler, .
  // FR1: sec. 15.11.1, 15.11.2, table 15-3, table 15-5, table 15-6. 
  TCCR1A = 1<<(COM1A1) | 0<<(COM1A0) | 0<<(COM1B1) | 0<<(COM1B0) | 1<<(WGM11) | 0<<(WGM10);
  TCCR1B = 1<<(WGM13) | 1<<(WGM12) | 0<<(CS12) | 0<<(CS11) | 1<<(CS10);
  
  // FR1: sec. 15.9.3, figure 15-1, figure 15-7
  // Define PWM characteristics
  // ICR1 defines PWM frequency with a 16-bit resolution (0-65535)
  //    PWM frequency for this particular implementation
  //    is defined by formula:
  //
  //    fpwm=fmcu/(N*(1+ICR1))
  //
  // OCR1A defines pulse width duty cycle with a 16-bit resolution (0-65535)
  ICR1 = 65535;
  OCR1A = ICR1/2;

  // FR1: sec. 15.11.8
  // Enable the Timer/Counter0 Output Compare A Match Interrupt (OCIE0A)
  // This may be necessary to fully enable the PWM output on OC1A/PB1
  // depending on algorithm functionality as per design requirements
  //    If required, corresponding ISR is to be defined before setup. E.g. ISR(TIMER1_COMPA_vect)
  //    else, avoid summoning TIMSK1.
  //    Note: Summoning TIMSK1 and leaving ISR underdefined may cause PWM comparators to misfire 
  TIMSK1 = 1<<(OCIE1A);
}

void loop() {
  // No need for anything here, as the PWM output is already configured and running
}
