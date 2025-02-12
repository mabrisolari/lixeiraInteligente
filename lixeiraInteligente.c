#include "pico/stdlib.h"
#include <stdio.h>

#define LIXO_SENSOR_PIN 2  // Substitua com o número do GPIO desejado para o sensor de nível de lixo
#define BOTAO_A_PIN 5    // Substitua com o número do GPIO desejado para o botão A
#define BOTAO_B_PIN 6     // Substitua com o número do GPIO desejado para o botão B
#define LED_VERMELHO_PIN 13 // Substitua com o número do GPIO desejado para o LED vermelho

int main() {
    stdio_init_all();  // Inicializa a saída padrão para printf

    // Inicializa os pinos dos sensores, botões e LED
    gpio_init(LIXO_SENSOR_PIN);
    gpio_set_dir(LIXO_SENSOR_PIN, GPIO_IN);
    gpio_pull_up(LIXO_SENSOR_PIN);  // Ativa o pull-up interno para o sensor de nível de lixo

    gpio_init(BOTAO_A_PIN);
    gpio_set_dir(BOTAO_A_PIN, GPIO_IN);
    gpio_pull_up(BOTAO_A_PIN);  // Ativa o pull-up interno para o botão A

    gpio_init(BOTAO_B_PIN);
    gpio_set_dir(BOTAO_B_PIN, GPIO_IN);
    gpio_pull_up(BOTAO_B_PIN);  // Ativa o pull-up interno para o botão B

    gpio_init(LED_VERMELHO_PIN);
    gpio_set_dir(LED_VERMELHO_PIN, GPIO_OUT);

    bool botao_a_pressionado = false;
    bool botao_b_pressionado = false;

    while (true) {
        // Verifica o nível de lixo
        if (gpio_get(LIXO_SENSOR_PIN) == 0) {  // Nível de lixo acima do limite
            printf("Mensagem enviada: Lixeira cheia\n");
            // Enviar notificação para a central de coleta (implementar comunicação)
        }

        // Verifica se o botão A foi pressionado
        if (gpio_get(BOTAO_A_PIN) == 0) {  // Botão A pressionado
            if (!botao_a_pressionado) {
                printf("Botão A pressionado: Lixeira A cheia\n");
                gpio_put(LED_VERMELHO_PIN, true);  // Acende o LED vermelho
                botao_a_pressionado = true;
            }
        } else {
            botao_a_pressionado = false;  // Botão A não pressionado
        }

        // Verifica se o botão B foi pressionado
        if (gpio_get(BOTAO_B_PIN) == 0) {  // Botão B pressionado
            if (!botao_b_pressionado) {
                printf("Botão B pressionado: Lixeira B cheia\n");
                gpio_put(LED_VERMELHO_PIN, true);  // Acende o LED vermelho
                botao_b_pressionado = true;
            }
        } else {
            botao_b_pressionado = false;  // Botão B não pressionado
        }

        sleep_ms(50);  // Debounce
    }
}
