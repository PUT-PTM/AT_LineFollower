#ifndef ADC_H_
#define ADC_H_

#define RedOff       PORTD |= (1<<PD4);
#define RedOn      PORTD &= ~(1<<PD4);
#define RedTogg     PORTD ^= (1<<PD4);
#define GreenOff     PORTD |= (1<<PD2);
#define GreenOn    PORTD &= ~(1<<PD2);
#define GreenTogg   PORTD ^= (1<<PD2);
#define YellowOff    PORTD |= (1<<PD3);
#define YellowOn   PORTD &= ~(1<<PD3);
#define YellowTogg  PORTD ^= (1<<PD3);

void ADCInit(void);

#endif
