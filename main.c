#include <avr/io.h>
#include <util/delay.h>

#include "Sensors.h"
#include "MotorsPWM.h"


int main(void){

    MotorsInit();
    SensorsInit();

    PORTC = 0;
    PORTC |= (1<<PC2) | (1<<PC4) | (1<<PC0);



    DDRD |= (1<<PD2) | (1<<PD3) | (1<<PD4);

    DDRB |= (1<<PB3);

    PORTB |= (1<<PB3);

    //Mot1 = 50;             //lewe
    //Mot2 = 48;           //prawe    ratio prawy/lewy -> 0.96

   uint8_t s1 = 0;
   uint8_t s2 = 0;

   uint8_t sensors[8];


    while(1){
         s1 = getSensorState(4);
         s2 = getSensorState(5);
         if (s1 || s2){
              Mot1 = 50;
              Mot2 = 50;
         }
         else{
              Mot1 = 0;
              Mot2 = 0;
         }

    }


}