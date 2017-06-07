/*
 * PDAlgorithm.h    atmega88p    F_CPU = 1000000 Hz
*/

#ifndef PDALGORITHM_H_
#define PDALGORITHM_H_

void read_sensors(void);
void get_error(void);
int get_PD(void);
void follow_line(void);

#endif  /* PDALGORITHM_H_ */
