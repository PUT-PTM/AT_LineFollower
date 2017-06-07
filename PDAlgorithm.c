
/*
 * PDAlgorithm.c    atmega88p    F_CPU = 1000000 Hz
*/
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

#include "MotorsPWM.h"
#include "Sensors.h"
#include "PDAlgorithm.h"
#include "uart.h"


#define REQ_VAL 0     // Pozadana pozycja(linia przebiega po srodku listwy)
#define KP 5          // Wzmocnienie reg P
#define KD 15          // Wzmocnienie reg D

int prev_err,act_err=0;
int flag=0;
int stop=0;
uint8_t SENSORS[8] = {0,0,0,0,0,0,0,0};
int WEIGHTS[8] = {-30, -25, -15, -5,5, 15, 25, 30};

char sensors[9];

#define GLEDON   PORTD &= ~(1<<PD2);
#define GLEDOFF  PORTD |= (1<<PD2);
#define YLEDON   PORTD &= ~(1<<PD3);
#define YLEDOFF  PORTD |= (1<<PD3);
#define RLEDON   PORTD &= ~(1<<PD4);
#define RLEDOFF  PORTD |= (1<<PD4);

void read_sensors()
{
 for(int i=1;i<=8;i++)
 {
      SENSORS[i-1] = getSensorState(i);
      if(SENSORS[i-1]){
           czujniki[i-1] = 'O';
      }else{
           czujniki[i-1] = 'X';
      }
 }
}

void get_error() {
    int actual_position = 0,active_sensors = 0,avg = 0;

    for(int i=1;i<=8;i++)
    {
        actual_position += (SENSORS[i-1] * WEIGHTS[i-1]);
        active_sensors += SENSORS[i-1];
    }
 
    if(active_sensors == 0)
    {
        stop=0;
    }
    else stop = 0;


    if(active_sensors  != 0) 
    {
        avg = (actual_position / active_sensors);
        act_err = REQ_VAL + avg;
    }
    else
    {
        if(prev_err <= -5)
        {
            act_err = -40;
            flag = 1;

        }
        else if(prev_err >= 5)
        {
            act_err = 40;
            flag = 2;

        }
        else
            act_err = 0;

    }

    if(flag == 1 && act_err <= 0)
        flag = 0;
    else if(flag == 2 && act_err >= 0)
        flag = 0;

    if(act_err == 40){
        RLEDON; GLEDOFF; YLEDOFF;
    }else if(act_err == -40){
        GLEDON; RLEDOFF; YLEDOFF;
    }else{
        YLEDON; GLEDOFF; RLEDOFF;
    }


    for(int i=1;i<=8;i++)
    {
       SENSORS[i-1] = 0;
    }
 }

int get_PD()
{
     int dx = act_err - prev_err;
     if (act_err != 0)
         prev_err = act_err;
     return (KP*act_err + KD*dx);
}

void follow_line()
{
     int reg = 0;
     read_sensors();
     get_error();
     reg = get_PD();
     uint8_t motdefault = 255;
     if( stop == 0)
     {
         if(reg < 0)
         {
            Mot1 = motdefault;
            Mot2 = motdefault + reg;
         }
         else if(reg > 0)
         {
            Mot1 = motdefault - reg;
            Mot2 = motdefault;
         }
         else
         {
            Mot1 = motdefault;
            Mot2 = motdefault;
         }
     }
     else
     {
        Mot1 = 0;
        Mot2 = 0;
     }

}
