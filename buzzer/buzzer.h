#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include "hardware/clocks.h"

#define BUZZER_PIN 21                // Configuração do pino do buzzer
extern const uint star_wars_notes[]; // Declaração da variável responsável por armazenar as notas da música
extern const uint note_duration[];   // Declaração da variável responsável por armazenar a duração da nota a ser tocada

// Inicializa o PWM no pino do buzzer
void pwm_init_buzzer(uint pin);
// Toca uma nota com a frequência e duração especificadas
void play_tone(uint pin, uint frequency, uint duration_ms);
// Função principal para tocar a música
void play_star_wars(uint pin);