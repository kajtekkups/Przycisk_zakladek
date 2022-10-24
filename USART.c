
#include "USART.h"


void USART_Init( unsigned int ubrr)
{
/*Set baud rate (UBRR register consist of 12 bits (4 more important in UBRR0H and 8 less important in UBRR0L)) */
UBRR0H = (unsigned char)(ubrr>>8); //writing just 4 most important bits
UBRR0L = (unsigned char)ubrr;
/* Enable receiver and transmitter */
UCSR0B = (1<<RXEN0)|(1<<TXEN0) & ~(1 << UCSZ02); 
/* Set frame format: 8data (7???), 1stop bit */
UCSR0C = (1 << UCSZ01) | (1 << UCSZ00) & ~(1 << USBS0);
}


void USART_Transmit( uint8_t data )
{
/* Wait for empty transmit buffer */
while ( !( UCSR0A & (1<<UDRE0)) );

/* Put data into buffer, sends the data */
UDR0 = data;

/* Wait until transmition is complete */
while ((UCSR0A & (1 << TXC0)) != (1 << TXC0));

}