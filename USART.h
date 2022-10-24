#include <avr/io.h>



//ubrr explained in datasheet page 182
void USART_Init(unsigned int ubrr); //setting USART on


void USART_Transmit( uint8_t data ); //transmiting data to a computer