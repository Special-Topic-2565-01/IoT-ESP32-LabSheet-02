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
        for (uint8_t i = 0; i < 8; i++)
        {
            gpio_set_level(LEDIO[i], 1);
            usleep(ON_time);
        }
        for (uint8_t i = 7; i > 0; i--)
        {
            gpio_set_level(LEDIO[i], 0);
            usleep(OFF_time);
        }
    }
}