#include "hardware/pio.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

// Definição dos pinos dos LEDs
#define LED_R 13
#define LED_G 11
#define LED_B 12

#define DIVIDER_PWM  16.0                              // Divisor fracional do clock para o PWM
extern uint16_t PERIOD;                                // Período do PWM (valor máximo do contador)
extern uint16_t led_r_level, led_b_level, led_g_level; // Inicialização dos níveis de PWM para os LEDs
extern uint slice_led_r, slice_led_b, slice_led_g;     // Variáveis para armazenar os slices de PWM correspondentes aos LEDs
extern uint16_t LED_STEP;                              // Incremento/Decremento da intensidade do LED
extern uint up_down;                                   // Variável para controlar se o nível do LED aumenta ou diminui

// Função para configurar o PWM de um LED
void setup_pwm_led(uint led, uint *slice, uint16_t level);
// Função para determinar a intensidade de dois LEDS conforme os valores dos eixos do joystick
void set_pwm_led_with_joystick();
// Função para aumentar a intensidade de um LED e depois diminuir
void set_pwm_led_intensity();