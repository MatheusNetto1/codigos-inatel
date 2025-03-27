#include <avr/io.h>

#define BOTAO_LIGA PD2     // Botão LIGA (Pino 2 do PORTD)
#define BOTAO_DESLIGA PD3  // Botão DESLIGA (Pino 3 do PORTD)
#define SENSOR_S1 PD4      // Sensor S1 (Pino 4 do PORTD)
#define MOTOR PB0          // Motor (Pino 0 do PORTB)
#define ALARME PB1         // Alarme (Pino 1 do PORTB)

int main() {
    DDRD &= ~(1 << BOTAO_LIGA);     // PD2 como entrada (botão LIGA)
    DDRD &= ~(1 << BOTAO_DESLIGA);  // PD3 como entrada (botão DESLIGA)
    DDRD &= ~(1 << SENSOR_S1);      // PD4 como entrada (sensor S1)

    DDRB |= (1 << MOTOR);   // PB0 como saída (motor)
    DDRB |= (1 << ALARME);  // PB1 como saída (alarme)

    PORTB &= ~(1 << MOTOR);   // Motor desligado
    PORTB &= ~(1 << ALARME);  // Alarme desligado

    while(true) {
        int estadoLiga = PIND & (1 << BOTAO_LIGA);     // Lê o botão LIGA
        int estadoDesliga = PIND & (1 << BOTAO_DESLIGA);  // Lê o botão DESLIGA
        int estadoS1 = PIND & (1 << SENSOR_S1);        // Lê o sensor S1

        if (estadoLiga && !(estadoS1)) {
            PORTB |= (1 << MOTOR);   // Liga o motor
            PORTB &= ~(1 << ALARME); // Desliga o alarme
        }

        if (estadoDesliga) {
            PORTB &= ~(1 << MOTOR);  // Desliga o motor
        }

        if (estadoS1) {
            PORTB &= ~(1 << MOTOR);  // Desliga o motor imediatamente
            PORTB |= (1 << ALARME);  // Liga o alarme
        }

        if (!(estadoS1) && estadoLiga) {
            PORTB &= ~(1 << ALARME);  // Desliga o alarme
        }

        _delay_ms(100);  // Pequeno atraso para evitar leituras muito rápidas
    }

    return 0;
}
