/*
 * MotorsPWM.c    atmega88p    F_CPU = 1000000 Hz
 *
 * Created on: 28.04.2017
 *     Author: admin
*/
#include <avr/io.h>
#include "MotorsPWM.h"



void MotorsInit(){
    // PWM OC1A oraz OC1B Fast PWM 8bit

    //OC1A
    DDRB |= (1<<PB1) | (1<<PB2);
    TCCR1A |= (1<<COM1A1);

    //OC1B
    TCCR1A |= (1<<COM1B1);

    //tryb
    TCCR1A |= (1<<WGM10); //FAST PWM 8bit
    TCCR1B |= (1<<WGM12);

    //ustawienie prescalera w timerze (uruchamianie timera)
    TCCR1B |= (1<<CS10); //prescaler 1 = 1MHz
}