#include <avr/io.h>

#define BOTAO_LIGA    (1 << PB0)
#define BOTAO_DESLIGA (1 << PB1)
#define SENSOR_S1     (1 << PB2)
#define SENSOR_S2     (1 << PB3)
#define SENSOR_S3     (1 << PB4)
#define CH1           (1 << PB5)
#define CH2           (1 << PB6)
#define LED_ON        (1 << PD2)
#define MOTOR         (1 << PD3)
#define LED_ALARME    (1 << PD4)

int main() {  
    DDRB &= ~(BOTAO_LIGA | BOTAO_DESLIGA | SENSOR_S1 | SENSOR_S2 | SENSOR_S3 | CH1 | CH2); // Configura os botões e sensores como entradas
    DDRD |= (LED_ON | MOTOR | LED_ALARME); // Configura LEDs e motor como saídas
    PORTD &= ~(LED_ON | MOTOR | LED_ALARME); // Inicia LEDs e motor desligados
    
    uint8_t sistema_ligado = 0;
    uint8_t caixa_detectada = 0;

    while(true) {
        if (PINB & BOTAO_LIGA) {
            sistema_ligado = 1;
            PORTD |= LED_ON;  // Liga o LED ON
            PORTD &= ~LED_ALARME;  // Desliga o LED ALARME
            _delay_ms(500);  // Anti-bouncing
        }
        
        if (PINB & BOTAO_DESLIGA) {
            sistema_ligado = 0;
            PORTD &= ~(LED_ON | MOTOR);  // Desliga o LED ON e o motor
            PORTD |= LED_ALARME;  // Liga o LED ALARME
            _delay_ms(500);  // Anti-bouncing
        }

        if (sistema_ligado) {
            uint8_t ch1 = PINB & CH1;
            uint8_t ch2 = PINB & CH2;
            
            if ((PINB & SENSOR_S1) && (ch1 || ch2)) {
                caixa_detectada = 1;
            } else if ((PINB & SENSOR_S2) && !ch1 && ch2) {
                caixa_detectada = 1;
            } else if ((PINB & SENSOR_S3) && !ch1 && !ch2) {
                caixa_detectada = 1;
            } else {
                caixa_detectada = 0;
            }

            if (caixa_detectada) {
                PORTD |= MOTOR;  // Liga o motor
            } else {
                PORTD &= ~MOTOR;  // Desliga o motor
            }
        }
    }

    return 0;
}
