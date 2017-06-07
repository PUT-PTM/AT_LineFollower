#include <avr/io.h>
#include "uart.h"

//NOTE: Code used for debug purposes

void USART_Init(uint8_t ubrr)
{

    /*Set baud rate */
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
    /* Enable receiver and transmitter */
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    /* Set frame format: 8data, 2stop bit */
    UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void USART_SendChar(uint8_t data )
{
    /* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1<<UDRE0)) );
    /* Put data into buffer, sends the data */
    UDR0 = data;
}

uint8_t USART_Receive()
{
   /* Wait for data to be received */
    while ( !(UCSR0A & (1<<RXC0)) )
    ;
    /* Get and return received data from buffer */
    return UDR0;
}

void USART_SendString(char text[]){

     uint8_t idx = 0;

     while(text[idx] != '\0'){
          USART_SendChar(text[idx]);
          idx++;
     }
}

void USART_SendStringNL(char text[]){

     uint8_t idx = 0;

     while(text[idx] != '\0'){
          USART_SendChar(text[idx]);
          idx++;
     }
     USART_SendChar('\r');  //cr
     USART_SendChar('\n');  //lf
}
