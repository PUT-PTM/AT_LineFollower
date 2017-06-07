#include <avr/io.h>
#include "Sensors.h"

void sensors_init(){

    /*
    * Initialization: Setting proper pins as inputs
    * and setting them into high logical value
    */

    DDRD &= ~(0b11100000);
    PORTD |= (0b11100000);

    DDRB &= ~(0b11110001);
    PORTB |= (0b11110001);

    //IR sensors on/off pin
    DDRB |= (1<<PB3);
    PORTB |= (1<<PB3);

}

uint8_t get_sensors_state(){
    /*
    * Returns sensors state as one byte.
    * Sensor 1 - bit 0  (youngest bit)
    * Sensor 2 - bit 1
    * itd
    * Sensor 8 - bit 7  (oldest bit)
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

uint8_t get_sensor_state(uint8_t sensorNumber){

    /*
    * Resturns sesnors state (as zero or non-zero)
    * Sensors numbered from 1-8
    */

    uint8_t state = getSensorsState();

    if(state & (1<<(sensorNumber-1))){
         return 1;
    }else{
         return 0;
    }

    return 0;
}
