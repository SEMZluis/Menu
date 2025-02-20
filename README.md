# Menu
O projeto é a minha resposta para a tarefa da unidade 6.1 do curso [Embarcatech](https://embarcatech.softex.br), que foi construída na placa [BitDogLab](https://github.com/BitDogLab/BitDogLab-C/tree/main). Ela utiliza como referência trechos de código do repositório e do material disponibilizados pelo curso.

Em resumo, a tarefa consiste em criar um menu a ser exibido em um display OLED. As opções no menu correspondem a outro projeto/código, o qual é executado quando a opção é selecionada. Enquanto um projeto está em execução, o usuário também pode voltar ao menu inicial.

# Loop Principal

```c
if (c != 0) {
        clear_display();
        draw_return();
        oldc = c;
```

Nessa primeira parte, o código verifica se o contador de cliques difere de zero. Se não for, significa que o usuário pressionou alguma das opções. Por isso, a tela é limpa e a opção de retornar para o menu inicial é exibida na tela. Além disso, é armazenado o valor atual do contador na variável `oldc`.

```c

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
```

Enquanto a variável `oldc` é igual ao contador de cliques, significa que o usuário não clicou para retornar ao menu inicial. Desse modo, enquanto esses valores forem iguais, uma das opções escolhidas pelo usuário será executada. Quando o usuário clica novamente no botão do joystick, a condição do laço de repetição é cumprida, os LEDs se apagam e a tela do display é limpa.

```c
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
```

Se o usuário não clicou ou decidiu voltar para o menu inicial, o contador de cliques será zerado. O menu e o seletor de opções serão exibidos no display e o joystick será lido conforme os seus movimentos. A opção escolhida mediante o periférico está diretamente relacionada ao eixo Y do display em que essa opção é exibida. A opção um está no valor 20, a dois no valor 40 e a três no valor 60. Com isso, é possível desenhar o seletor de opções conforme o valor da leitura do joystick: se o periférico foi movido para baixo, o seletor desce, se o periférico foi movido para cima, o seletor sobe.