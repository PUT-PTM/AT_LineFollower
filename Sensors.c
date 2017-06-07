    #include <avr/io.h>
#include "Sensors.h"

 /*
 * Czujniki pod³¹czone wed³ug schematu
 * https://easyeda.com/agedee34/LineFollower_PTM-ebb706302d924e61a77a70f42d5fbbeb
 */


void SensorsInit(){

    /*
    * Inicjalizacja: Ustawienie odpowiednich pinów jako wejœcia
    * oraz ustawienie ich w stan wysoki
    */

    DDRD &= ~(0b11100000); //PB5,6,7 jako wejscia
    PORTD |= (0b11100000); //PD5,6,7 na stan wysoki

    DDRB &= ~(0b11110001); //PB0,4,5,6,7 jako wejscia
    PORTB |= (0b11110001); //PB0,4,5,6,7 na stan wysoki

    //Czujniki IR on/off pin
    DDRB |= (1<<PB3);
    PORTB |= (1<<PB3);

}

uint8_t getSensorsState(){
    /*
    * Zwraca stan czujników jako jeden bajt.
    * Czujnik 1 - bajt 0  (najm³odszy bit)
    * Czujnik 2 - bajt 1
    * itd
    * Czujnik 8 - bajt 7  (najstarszy bit)
    */

     uint8_t state = 0;

     state |= ( (1<<PB5) & PINB ) >> 5; //Czujnik 1
     state |= ( (1<<PB4) & PINB ) >> 3; //Czujnik 2
     state |= ( (1<<PB6) & PINB ) >> 4; //Czujnik 3
     state |= ( (1<<PB7) & PINB ) >> 4; //Czujnik 4
     state |= ( (1<<PD5) & PIND ) >> 1; //Czujnik 5
     state |= ( (1<<PD6) & PIND ) >> 1; //Czujnik 6
     state |= ( (1<<PD7) & PIND ) >> 1; //Czujnik 7
     state |= ( (1<<PB0) & PINB ) << 7; //Czujnik 8

     return state;
}

uint8_t getSensorState(uint8_t sensorNumber){

    /*
    * Zwraca stan danego czujnika jako 0 lub nie-zero
    * Czujniki 1 do 8
    */

    uint8_t state = getSensorsState();

    if(state & (1<<(sensorNumber-1))){
         return 1;
    }else{
         return 0;
    }

    return 0;
}