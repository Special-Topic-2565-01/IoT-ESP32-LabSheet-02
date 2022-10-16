#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"

uint32_t ON_time = 500000;
uint32_t OFF_time = 0;

uint8_t LEDIO[8] = {23, 22, 1, 3, 21, 19, 18, 5};

void app_main(void)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        gpio_reset_pin(LEDIO[i]);
    }

    for (uint8_t i = 0; i < 8; i++)
    {
        gpio_set_direction(LEDIO[i], GPIO_MODE_OUTPUT);
    }

    uint8_t ledNum = 0;

    while (true)
    {
        gpio_set_level(LEDIO[ledNum], 1);
        usleep(ON_time);
        gpio_set_level(LEDIO[ledNum], 0);
        usleep(OFF_time);
        ledNum++;
        if (ledNum == 8)
            ledNum = 0;
    }
}