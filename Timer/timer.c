#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
void mydelay()
{
    DDRB|=0x20;
    cli(); // to disable interrupts
    OCR1A = 62499;// for setting compare value
    TCCR1B |= 0b00001100; //setting timer/counter control register B for 256 prescalar and WGMI2 high for begining CTC MODE   
    TIMSK1 |= 0b00000010;// OCIE1A (switching on compare interrupt enable)
    sei();
}
  void sleep()
{
  SMCR |= 0b00000110; // for power save mode
  MCUCR |= 0b01100000;// for BODSE and BODS 
  MCUCR |= 0b01000000; // for BODS to disable brown out reset
  PRR |= 0b11100111; // for TWI/SPI/USART/ADC
  SMCR |= 0b00000001; // for enabling sleep mode
  //WDTON = 1;
  sleep_cpu ();
}
int main()
{  
  mydelay();
  sleep();    
  while(1);
 return 0; 
}
ISR(TIMER1_COMPA_vect)
{
     PORTB^=0x20;// toggling led
}
