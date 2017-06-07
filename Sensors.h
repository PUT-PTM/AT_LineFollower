#ifndef SENSORS_H_
#define SENSORS_H_

void sensors_init(void);
uint8_t get_sensors_state(void);
uint8_t get_sensor_state(uint8_t sensorNumber);

#endif
