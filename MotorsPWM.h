/*
 * MotorsPWM.h    atmega88p    F_CPU = 1000000 Hz
 *
 * Created on: 28.04.2017
 *     Author: admin
*/

#ifndef MOTORSPWM_H_
#define MOTORSPWM_H_

#define Mot1 OCR1A
#define Mot2 OCR1B

void MotorsInit(void);

#endif  /* MOTORSPWM_H_ */