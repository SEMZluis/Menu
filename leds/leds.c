#include "leds.h"
#include "joystick/joystick.h"

uint16_t PERIOD = 2000;
uint16_t LED_STEP = 100;
uint16_t led_r_level, led_b_level, led_g_level = 100;
uint slice_led_r, slice_led_b, slice_led_g;
uint up_down = 1;

void setup_pwm_led(uint led, uint *slice, uint16_t level) {
    gpio_set_function(led, GPIO_FUNC_PWM); 
    *slice = pwm_gpio_to_slice_num(led);   
    pwm_set_clkdiv(*slice, DIVIDER_PWM);   
    pwm_set_wrap(*slice, PERIOD);         
    pwm_set_gpio_level(led, 0);            
    pwm_set_enabled(*slice, true);         
}

void set_pwm_led_with_joystick() {
    read_joystick_axis(&vry_value, &vrx_value);
    pwm_set_gpio_level(LED_R, vry_value);
    pwm_set_gpio_level(LED_B, vrx_value);
    sleep_ms(2);
}

void set_pwm_led_intensity() {
    pwm_set_gpio_level(LED_B, led_b_level);
    sleep_ms(1000);

    if (up_down) {
        led_b_level += LED_STEP;
        if (led_b_level >= PERIOD)
            up_down = 0;
    } else {
        led_b_level -= LED_STEP;
        if (led_b_level <= LED_STEP)
            up_down = 1;
    }
}