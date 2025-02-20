#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "inc/ssd1306.h"
#include "hardware/i2c.h"
#include "pico/binary_info.h"
#include <ctype.h>

// Definição dos pinos do OLED
#define SDA_PIN 14
#define SCL_PIN 15

// Definição do buffer e da área de renderização
extern uint8_t ssd[ssd1306_buffer_length];
extern struct render_area frame_area;  

// Função para limpar os dados exibidos no display OLED
void clear_display();
// Função para limpar somente o seletor exibido no display
void clear_selector(uint line);
// Função para configurar o display OLED
void oled_setup();
// Função para exibir o menu no display
void draw_menu();
// Função para exibir o seletor no display
void draw_selector(uint line);
// Função para exibir a opção de retorno no display
void draw_return();