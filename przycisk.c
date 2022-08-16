

//Preambula
#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"

// #define FOSC 1843200 // Clock Speed
#define FOSC 1000000UL // Clock Speed
#define BAUD 9600
#define MY_UBRR FOSC/16/BAUD-1 //explained in datasheet pasge 182

int main(void){

    DDRB = 0x0;
    PORTB |= (1 << PB0) | (1 << PB1) | (1 << PB2);

    DDRB |= (1 << PB3);

    USART_Init(MY_UBRR);
    //PB0, PB1, PB2 - guzik   PB3 - dioda

    while (1){
        

        if((PINB & (1 << PB0)) != (1 << PB0)){
            PORTB |= (1 << PB3);
            USART_Transmit(1);
            while((PINB & (1 << PB0)) != (1 << PB0));
        }
        else if((PINB & (1 << PB1)) != (1 << PB1)){
            USART_Transmit(2);
            _delay_ms(100);
            PORTB &= ~(1 << PB3);
            while((PINB & (1 << PB1)) != (1 << PB1));
        }
        else if((PINB & (1 << PB2)) != (1 << PB2)){
            USART_Transmit(3);
            _delay_ms(100);
            while((PINB & (1 << PB2)) != (1 << PB2));
        }
    }
    return (0);
}