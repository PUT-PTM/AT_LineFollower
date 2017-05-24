#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "Sensors.h"
#include "MotorsPWM.h"
#include "PDAlgorithm.h"

#include "uart.h"


int main(void){

    MotorsInit();
    SensorsInit();
    USART_Init(12);     //baud 4800 0.2% error

    sei(); //w³¹czenie przerwañ

    //3 diody
    DDRD |= (1<<PD2) | (1<<PD3) | (1<<PD4);
    //

    while(1)
    {
        lets_follow();
    }


}
