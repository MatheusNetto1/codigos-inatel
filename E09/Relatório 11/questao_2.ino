#include <avr/io.h>

#define LEITURA_BUTTON_PIN PD2  // Botão LEITURA no PD2 (INT0)
#define LED_PIN PB0             // LED no PB0

uint16_t previousReading = 0;
uint8_t counter = 0;

// Interrupção do botão LEITURA
ISR(INT0_vect) {
    ADCSRA |= (1 << ADSC);                                      // Inicia uma conversão ADC
    while (ADCSRA & (1 << ADSC));                               // Espera conversão terminar

    uint16_t currentReading = ADC;
    if (previousReading == 0) {
        previousReading = currentReading;                       // Define leitura inicial
    } else if (currentReading < previousReading * 0.8) {
        counter++;                                              // Incrementa o contador se leitura for 20% menor
        previousReading = currentReading;
    }
}

int main() {
    // Configuração dos pinos
    DDRD &= ~(1 << LEITURA_BUTTON_PIN);                         // Botão como entrada
    DDRB |= (1 << LED_PIN);                                     // LED como saída

    // Configuração do ADC
    ADMUX = (1 << REFS0);                                       // Referência AVcc
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);         // Habilita ADC, pre-scaler 64

    // Configuração de interrupção externa no botão
    EICRA |= (1 << ISC01);                                      // INT0 para borda de descida
    EIMSK |= (1 << INT0);                                       // Habilita INT0

    sei();

    while (1) {
        if (counter >= 5 && counter < 10) {
            PORTB |= (1 << LED_PIN);                            // Liga LED
        } else if (counter >= 10) {
            PORTB ^= (1 << LED_PIN);                            // Alterna LED (piscando)
            _delay_ms(250);
        } else {
            PORTB &= ~(1 << LED_PIN);                           // Desliga LED
        }
    }

    return 0;
}