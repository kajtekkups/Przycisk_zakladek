

//Preambula
#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"


// Clock Speed (FOSC) 1000000 
// BAUD 9600
#define MY_UBRR 6 // (FOSC/(16*BAUD))-1 explained in datasheet pasge 182


int main(void){

    //PB0, PB1, PB2 - guzik   PB3 - dioda
    DDRB = 0x0;
    PORTB |= (1 << PB0) | (1 << PB1) | (1 << PB2);
    DDRB |= (1 << PB3);

    USART_Init(MY_UBRR);
    

    while (1){
        

        if((PINB & (1 << PB0)) != (1 << PB0)){
            
            PORTB |= (1 << PB3);
            USART_Transmit(1);
            USART_Transmit(10);
            while((PINB & (1 << PB0)) != (1 << PB0));
        }
        else if((PINB & (1 << PB1)) != (1 << PB1)){
            
            PORTB &= ~(1 << PB3);
            USART_Transmit(2);
            USART_Transmit(10);
            while((PINB & (1 << PB1)) != (1 << PB1));
        }
        else if((PINB & (1 << PB2)) != (1 << PB2)){
           
            USART_Transmit(3);
           USART_Transmit(10);
            while((PINB & (1 << PB2)) != (1 << PB2));
        }
    }
    return (0);
}