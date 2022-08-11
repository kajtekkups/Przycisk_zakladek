//kopia programu povToy

//Preambula
#include <avr/io.h>
#include <util/delay.h>


int main(void){

    DDRB = 0x0;
    PORTB |= (1 << PB0) | (1 << PB1) | (1 << PB2);

    DDRB |= (1 << PB3);


    //PB0, PB1, PB2 - guzik   PB3 - dioda

    while (1){
        
        if((PINB & (1 << PB0)) != (1 << PB0)){
            PORTB |= (1 << PB3);
        }else if((PINB & (1 << PB1)) != (1 << PB1)){
            PORTB &= ~(1 << PB3);
        }
    }
    return (0);
}