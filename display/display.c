#include "display.h"

uint8_t ssd[ssd1306_buffer_length]; 
struct render_area frame_area = { 
        start_column : 0,
        end_column : ssd1306_width - 1,
        start_page : 0,
        end_page : ssd1306_n_pages - 1
};

void clear_display() {
    memset(ssd, 0, ssd1306_buffer_length);
    render_on_display(ssd, &frame_area);
}

void clear_selector(uint line) {
    for (int x = 105; x < 114; x++) {
        for (int y = 0; y < 64; y++) {
            ssd1306_set_pixel(ssd, x, y, false);
        }
    }
    render_on_display(ssd, &frame_area);
}

void oled_setup() {
    i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    ssd1306_init();

    calculate_render_area_buffer_length(&frame_area);

    clear_display();
}

void draw_menu() {
     char *texto[] = {
        " JOYSTICK LED ",
        " TOCAR BUZZER ",
        " LED RGB      "
    };

    int y = 10;

    for (uint i = 0; i < 3; i++) {
        ssd1306_draw_string(ssd, 0, y, texto[i]);
        y = y + 20;
        sleep_ms(45);
    }

    render_on_display(ssd, &frame_area);
}

void draw_selector(uint line) {
    ssd1306_draw_string(ssd, 107, line, "X");
    render_on_display(ssd, &frame_area);
}

void draw_return() {
    ssd1306_draw_string(ssd, 0, 0, " VOLTAR X ");
    render_on_display(ssd, &frame_area);
}