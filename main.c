#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "Sensors.h"
#include "MotorsPWM.h"
#include "PDAlgorithm.h"

#include "uart.h" //debug purposes


int main(void){

    motors_init();
    sensors_init();
    USART_Init(12);     //baud 4800 0.2% error

    sei(); //built-in, turning interrupts

    //Diodes (sygnalizing turning direction)
    DDRD |= (1<<PD2) | (1<<PD3) | (1<<PD4);

    while(1)
    {
        follow_line();
    }


}
