/*
 * Sensors.h    atmega88p    F_CPU = 1000000 Hz
 *
 * Created on: 28.04.2017
 *     Author: admin
*/

#ifndef SENSORS_H_
#define SENSORS_H_

void SensorsInit(void);
uint8_t getSensorsState(void);
uint8_t getSensorState(uint8_t sensorNumber); //powinno raczej zwracaæ bool ale nie ma takiego typu danych, a poza tym bool ma jeden bajt tak samo jak uint8_t, wiec sie nie marnuje nic pamieci

#endif  /* SENSORS_H_ */