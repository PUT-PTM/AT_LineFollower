/*
 * PDAlgorithm.h    atmega88p    F_CPU = 1000000 Hz
 *
 * Created on: 17.05.2017
 *     Author: admin
*/

#ifndef PDALGORITHM_H_
#define PDALGORITHM_H_

void read_sensors(void);
void get_error(void);
int get_PD(void);
void lets_follow(void);

#endif  /* PDALGORITHM_H_ */