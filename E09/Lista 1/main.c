#include <avr/io.h>

int main(void) {

    // Questão 1
    DDRD |= (1 << PD2);
    PORTD |= (1 << PD2);

    // Questão 2
    PORTD &= ~(1 << PD2); 

    // Questão 3
    DDRD |= (1 << PD3);
    DDRB |= (1 << PB4);
    for(;;){
        PORTD ^= (1 << PD3);
        PORTB ^= (1 << PB4);  
    }

    // Questão 4
    DDRD &= ~(1 << PD5);
    PORTD |= (1 << PD5);
    for(;;){
        if(PIND & (1 << PD5)){
            //
        }
    }

    // Questão 5
    DDRD &= ~(1 << PD5);
    PORTD |= (1 << PD5);
    for(;;){
        if(PIND & (1 << PD5)){
            PORTD &= ~(1 << PD5);
        }
    }
    

    // Questão 6
    DDRD |= (1 << PD6) | (1 << PD7);
    PORTD &= ~(1 << PD6);

    // Questão 7
    DDRD &= ~(1 << PD2);
    DDRD |= (1 << PD3);
    for(;;){
        if(PIND & (1 << PD2)){
            PORTD |= (1 << PD3);
        }
    }

    // Questão 8
    DDRD &= ~(1 << PD2);
    DDRD |= (1 << PD3);
    for(;;){
        if(PIND & (1 << PD2)){
            PORTD &= ~(1 << PD3);
        }
    }

    // Questão 9
    DDRD |= (1 << PD4) | (1 << PD5) | (1 << PD6);

    // Questão 10
    DDRD &= ~(1 << PD0);
    DDRD &= ~(1 << PD1);
    DDRD &= ~(1 << PD2);
    for(;;){
        if ((DDRD & ((1 << PD0) | (1 << PD1) | (1 << PD2))) == 0){
            //
        }
    }

    // Questão 11
    DDRD &= ~(1 << PD0);
    PORTD |= (1 << PD0);
    DDRD |= (1 << PD1);

    for(;;){
        if (!(PIND & (1 << PD0))) { 
            PORTD ^= (1 << PD1);
        }
    }

    // Questão 12
    DDRD &= ~(1 << PD0);
    PORTD |= (1 << PD0);
    DDRD |= (1 << PD1);
    DDRD |= (1 << PD2);

    for(;;){
        if (!(PIND & (1 << PD0))) {
            if(((PIND & (1 << PD1)) && !(PIND & (1 << PD2))) || (!(PIND & (1 << PD1)) && PIND & (1 << PD2))){
                PORTD ^= (1 << PD1);
                PORTD ^= (1 << PD2);
            }
        }
    }

    // Questão 13
    DDRB &= ~(1 << PB0);
    DDRB &= ~(1 << PB1);
    DDRB &= ~(1 << PB2);
    DDRB &= ~(1 << PB3);
    DDRB &= ~(1 << PB4);
    DDRD |= (1 << PD1);
    DDRC |= (1 << PC2);

    for(;;){
        uint8_t interc1 = PINB &(1 << PB0) && !(PINB &(1 << PB1)) && PINB &(1 << PB2) && !(PINB &(1 << PB3)) && PINB &(1 << PB4);
        uint8_t interc2 = !(PINB &(1 << PB0)) && PINB &(1 << PB1) && !(PINB &(1 << PB2)) && PINB &(1 << PB3) && !(PINB &(1 << PB4));
        
        uint8_t allLow = !(PINB &(1 << PB0)) && !(PINB &(1 << PB1)) && !(PINB &(1 << PB2)) && !(PINB &(1 << PB3)) && !(PINB &(1 << PB4));
        uint8_t allHigh = PINB &(1 << PB0) && PINB &(1 << PB1) && PINB &(1 << PB2) && PINB &(1 << PB3) && PINB &(1 << PB4);

        if(interc1 || interc2){
            PORTD |= (1 << PD1);
            PORTC &= ~(1 << PC2);
        }

        else if(allLow || allHigh){
            PORTD &= ~(1 << PD1);
            PORTD |= (1 << PC2);
        }

        else{
            PORTD &= ~(1 << PD1);
            PORTC &= ~(1 << PC2);
        }
    }

    // Questão 14
    DDRB &= ~(1 << PB1);
    DDRB &= ~(1 << PB2);
    DDRB &= ~(1 << PB3);
    DDRB &= ~(1 << PB4);
    DDRD |= (1 << PD3);
    PORTB |= (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB4);
    for(;;){
        if(!(PINB & (1 << PB2)))
            if(!(PINB & (1 << PB2)) && !(PINB & (1 << PB3)))
                if(!(PINB & (1 << PB2)) && !(PINB & (1 << PB3)) && !(PINB & (1 << PB4)))   
                    if(!(PINB & (1 << PB2)) && !(PINB & (1 << PB3)) && !(PINB & (1 << PB4)) && !(PINB & (1 << PB1)))
                        PORTD |= (1 << PD3);     
    }
}