#include <stdio.h>
#include "pico/stdlib.h"
#include "leds/leds.h"
#include "joystick/joystick.h"
#include "display/display.h"
#include "buzzer/buzzer.h"

volatile uint option = 10; // Opção escolhida pelo seletor (ela é igual ao valor de y dos textos do menu, em pixels, na tela do display)

int main() {
    stdio_init_all();            // Inicialização da comunicação serial
    joystick_setup();            // Inicialização do joystick
    oled_setup();                // Inicialização do display
    pwm_init_buzzer(BUZZER_PIN); // Inicialização do buzzer

    // Inicialização dos LEDs com PWM
    setup_pwm_led(LED_R, &slice_led_r, led_r_level);
    setup_pwm_led(LED_G, &slice_led_g, led_g_level);
    setup_pwm_led(LED_B, &slice_led_b, led_b_level); 

    // Interrupção para o botão do joystick
    gpio_set_irq_enabled_with_callback(SW, GPIO_IRQ_EDGE_FALL, true, &sw_irq_handler);

    while(true) {
        if (c != 0) {
            clear_display();
            draw_return();
            oldc = c;
            
            while(oldc == c) {
                switch (option) {
                    case 10:
                        set_pwm_led_with_joystick();
                        break;
                    case 30:
                        play_star_wars(BUZZER_PIN);
                        break;
                    case 50:
                        set_pwm_led_intensity();
                        break;
                }
                sleep_ms(70);
            }

            setup_pwm_led(LED_R, &slice_led_r, 0);
            setup_pwm_led(LED_G, &slice_led_g, 0);
            setup_pwm_led(LED_B, &slice_led_b, 0); 
            clear_display();
        }
    
        c = 0;

        draw_menu();
        draw_selector(option);
        read_joystick_axis(&vry_value, &vrx_value);

        if (vry_value < 1000 & option != 50) {
            option+=20;
            clear_selector(option);
        } else if (vry_value > 2100 & option != 10) {
            option-=20;
            clear_selector(option);
        }

        sleep_ms(100);
    }

    return 0;
}
