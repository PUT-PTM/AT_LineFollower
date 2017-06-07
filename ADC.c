/*
 * ADC.c    atmega88p    F_CPU = 1000000 Hz
 *
 * Created on: 16.05.2017
 *     Author: admin
*/
#include <avr/io.h>
#include "ADC.h"

void adc_init()
{
    // AREF = AVcc
    ADMUX |= (1<<REFS0) | (1<<MUX2) | (1<<MUX0);
 
    // ADC Enable and prescaler of 128
    // 1 000 000 / 2 = 500 000
    ADCSRA = (1<<ADEN);
}

uint16_t adc_read(uint8_t ch)
{
  // select the corresponding channel 0~7
  // ANDing with ’7? will always keep the value
  // of ‘ch’ between 0 and 7
  ch &= 0b00000111;  // AND operation with 7
  ADMUX = (ADMUX & 0xF8)|ch; // clears the bottom 3 bits before ORing
 
  // start single convertion
  // write ’1? to ADSC
  ADCSRA |= (1<<ADSC);
 
  // wait for conversion to complete
  // ADSC becomes ’0? again
  // till then, run loop continuously
  while(ADCSRA & (1<<ADSC));
 
  return (ADC);
}