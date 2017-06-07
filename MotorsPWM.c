/*
 * MotorsPWM.c    atmega88p    F_CPU = 1000000 Hz
*/
#include <avr/io.h>
#include "MotorsPWM.h"



void motors_init(){

    //setting AIN1 direction
    PORTC = 0;
    PORTC |= (1<<PC2) | (1<<PC4) | (1<<PC0);

    // PWM OC1A and OC1B Fast PWM 8bit

    //OC1A
    DDRB |= (1<<PB1) | (1<<PB2);
    TCCR1A |= (1<<COM1A1);

    //OC1B
    TCCR1A |= (1<<COM1B1);

    //mode
    TCCR1A |= (1<<WGM10); //FAST PWM 8bit
    TCCR1B |= (1<<WGM12);

    //setting timer prescaler (timer running)
    TCCR1B |= (1<<CS10); //prescaler 1 = 1MHz
}
