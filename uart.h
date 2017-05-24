/*
 * uart.h    atmega88    F_CPU = 1000000 Hz
 *
 * Created on: 24.05.2017
 *     Author: admin
*/

#ifndef UART_H_
#define UART_H_

#define FOSC 1000000// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void USART_Init(uint8_t ubrr);
void USART_SendChar(uint8_t data);
uint8_t USART_Receive();
void USART_SendString(char text[]);
void USART_SendStringNL(char text[]);


#endif  /* UART_H_ */


/**             USART Interrupt Example              ****************


ISR(USART_RXC_vect)
{
   char ReceivedByte;
   ReceivedByte = UDR0; // Fetch the received byte value into the variable "ByteReceived"
   UDR0 = ReceivedByte; // Echo back the received byte back to the computer
}



*///