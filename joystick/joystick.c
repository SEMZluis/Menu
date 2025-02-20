#include "joystick.h"

volatile int c = 0;           
int oldc = 0;                 
uint16_t vry_value;           
uint16_t vrx_value; 

void joystick_setup() {
    adc_init();
    adc_gpio_init(VRY);

    gpio_init(SW);
    gpio_set_dir(SW, GPIO_IN);
    gpio_pull_up(SW);
}

void read_joystick_axis(uint16_t *vry_value, uint16_t *vrx_value) {
    adc_select_input(ADC0);
    sleep_ms(10);
    *vry_value = adc_read();

    adc_select_input(ADC1);
    sleep_ms(10);
    *vrx_value = adc_read();
}

void sw_irq_handler(uint gpio, uint32_t events) {
    c++;
}