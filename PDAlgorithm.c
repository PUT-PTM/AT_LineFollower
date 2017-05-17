/*
 * PDAlgorithm.c    atmega88p    F_CPU = 1000000 Hz
 *
 * Created on: 17.05.2017
 *     Author: admin
*/
#include <avr/io.h>
#include "MotorsPWM.c"
#include "MotorsPWM.h"
#include "Sensors.c"
#include "Sensors.h"

#define REQ_VAL 0     // Pozadana pozycja(linia przebiega po srodku listwy)
#define KP 1          // Wzmocnienie reg P
#define KD 0          // Wzmocnienie reg D

int prev_err,act_err=0;
int flag=0;
uint8_t SENSORS[8];
uint8_t WEIGHTS[8] = {-30, -20, -10, 0, 0, 10, 20, 30};

void read_sensors()
{
 for(int i=1;i<=8;i++)
 {
      SENSORS[i]= getSensorState(i);
 }
}
void get_error() {
    int actual_position,active_sensors,avg = 0;

    for(int i=1;i<=8;i++)
    {
        actual_position += (SENSORS[i] * WEIGHTS[i]);
        active_sensors += SENSORS[i];
    }

    if(active_sensors != 0) {
    avg = (actual_position / active_sensors);
    act_err = REQ_VAL + avg;
    }
    else
    {
        if(prev_err < -10)
        {
            act_err = -30;
            flag = 1;
        }
        else if(prev_err > 10)
        {
            act_err = 30;
            flag = 2;
        }
        else
            act_err = 0;
    }

    if(flag == 1 && act_err >= 0)
    flag = 0;
    else if(flag == 2 && act_err <= 0)
    flag = 0;
 }

int get_PD()
{
     int dx = act_err - prev_err;
     prev_err = act_err;

     return (KP*act_err + KD*dx);
}

void lets_follow()
{
     int reg = 0;
     read_sensors();
     get_error();
     reg = get_PD();
     Mot1 = 50 + reg;  // Musimy przyjac stala wartosc V z jaka robot ma jechac, teraz jest 50
     Mot2 = 50 - reg;
}

