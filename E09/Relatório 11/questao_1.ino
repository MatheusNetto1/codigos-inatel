#include <avr/io.h>

#define LIGA_BUTTON_PIN PD2      // Botão LIGA no PD2 (INT0)
#define DESLIGA_BUTTON_PIN PD3   // Botão DESLIGA no PD3 (INT1)
#define LED1_PIN PB0             // LED 1 no PB0
#define LED2_PIN PB1             // LED 2 no PB1
#define MOTOR_PIN PB3            // Motor PWM no PB3 (OC0A)

uint8_t motorOn = 0;
uint8_t pwmValue = 0;

// Interrupção do botão LIGA
ISR(INT0_vect) {
    motorOn = 1;
    pwmValue = 0;
    PORTB |= (1 << LED1_PIN);                           // Liga LED1 ao iniciar
}

// Interrupção do botão DESLIGA
ISR(INT1_vect) {
    motorOn = 0;
    pwmValue = 0;
    OCR0A = 0;                                          // Desliga o motor
    PORTB &= ~((1 << LED1_PIN) | (1 << LED2_PIN));      // Desliga LEDs
}

int main() {
    // Configuração dos pinos
    DDRD &= ~((1 << LIGA_BUTTON_PIN) | (1 << DESLIGA_BUTTON_PIN));      // Botões como entrada
    DDRB |= (1 << LED1_PIN) | (1 << LED2_PIN) | (1 << MOTOR_PIN);       // LEDs e motor como saída

    // Configuração do Timer0 para PWM no motor
    TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);              // Modo Fast PWM, OC0A como saída PWM
    TCCR0B |= (1 << CS01);  // Pre-scaler de 8

    // Configuração das interrupções nos botões
    EICRA |= (1 << ISC01) | (1 << ISC11);                               // INT0 e INT1 para borda de descida
    EIMSK |= (1 << INT0) | (1 << INT1);                                 // Habilita INT0 e INT1

    sei();

    while (1) {
        if (motorOn) {
            if (pwmValue < 255) {
                pwmValue++;
                OCR0A = pwmValue;
                _delay_ms(39);                          // Aproximadamente 10 segundos para atingir 100%

                if (pwmValue >= 127) {                  // Quando atinge 50% da velocidade
                    PORTB &= ~(1 << LED1_PIN);          // Desliga LED1
                    PORTB |= (1 << LED2_PIN);           // Liga LED2
                }
            }
        }
    }

    return 0;
}