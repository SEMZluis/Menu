#include "hardware/pio.h"
#include "hardware/adc.h"
#include "pico/stdlib.h"

#define VRX 26              // Pino de leitura do eixo X do joystick (conectado ao ADC)
#define VRY 27              // Pino de leitura do eixo Y do joystick (conectado ao ADC)
#define ADC0 0              // Canal ADC para o eixo Y do joystick
#define ADC1 1              // Canal ADC para o eixo X do joystick
#define SW 22               // Pino de leitura do botão do joystick
extern uint16_t vry_value;  // Variável responsável por armazenar o valor do eixo Y do joystick
extern uint16_t vrx_value;  // Variável responsável por armazenar o valor do eixo X do joystick
extern volatile int c;      // Variável responsável por contar se o botão foi pressionado ou não
extern int oldc;            // Variável responsável por armazenar o valor antigo do contador depois que ele foi pressionado (se os valores forem diferentes em algum momento, significa que o botão foi pressionado de novo)

// Função para configuração dos eixos do joystick e do botão
void joystick_setup(); 
// Função para realizar a leitura dos eixos do joystick
void read_joystick_axis(uint16_t *vry_value, uint16_t *vrx_value); 
// Interrupção disparada quando o botão do joystick é pressionado
void sw_irq_handler(uint gpio, uint32_t events); 