#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"

uint32_t ON_time = 50000;
uint32_t OFF_time = 50000;
uint8_t LEDIO[8] = {23, 22, 1, 3, 21, 19, 18, 5};

void app_main(void)
{
    for (uint8_t i = 0; i < 8; i++)
        gpio_reset_pin(LEDIO[i]);

    for (uint8_t i = 0; i < 8; i++)
        gpio_set_direction(LEDIO[i], GPIO_MODE_OUTPUT);

    while (true)
    {
        gpio_set_level(LEDIO[3], 1);
        gpio_set_level(LEDIO[4], 1);
        usleep(ON_time);
        gpio_set_level(LEDIO[3], 0);
        gpio_set_level(LEDIO[4], 0);
        usleep(OFF_time);
        gpio_set_level(LEDIO[2], 1);
        gpio_set_level(LEDIO[5], 1);
        usleep(ON_time);
        gpio_set_level(LEDIO[2], 0);
        gpio_set_level(LEDIO[5], 0);
        usleep(OFF_time);
        gpio_set_level(LEDIO[1], 1);
        gpio_set_level(LEDIO[6], 1);
        usleep(ON_time);
        gpio_set_level(LEDIO[1], 0);
        gpio_set_level(LEDIO[6], 0);
        usleep(OFF_time);
        gpio_set_level(LEDIO[0], 1);
        gpio_set_level(LEDIO[7], 1);
        usleep(ON_time);
        gpio_set_level(LEDIO[0], 0);
        gpio_set_level(LEDIO[7], 0);
        usleep(OFF_time);

        gpio_set_level(LEDIO[1], 1);
        gpio_set_level(LEDIO[6], 1);
        usleep(ON_time);
        gpio_set_level(LEDIO[1], 0);
        gpio_set_level(LEDIO[6], 0);
        usleep(OFF_time);
        gpio_set_level(LEDIO[2], 1);
        gpio_set_level(LEDIO[5], 1);
        usleep(ON_time);
        gpio_set_level(LEDIO[2], 0);
        gpio_set_level(LEDIO[5], 0);
        usleep(OFF_time);
    }
}