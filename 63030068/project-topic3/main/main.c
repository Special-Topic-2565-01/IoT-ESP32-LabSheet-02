#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"

uint32_t ON_time = 1000000;
uint32_t OFF_time = 1000000;

void app_main(void)
{
    gpio_reset_pin(23);
    gpio_reset_pin(22);
    gpio_reset_pin(1);
    gpio_reset_pin(3);
    gpio_reset_pin(21);
    gpio_reset_pin(19);
    gpio_reset_pin(18);
    gpio_reset_pin(5);

    gpio_set_direction(23, GPIO_MODE_OUTPUT);
    gpio_set_direction(22, GPIO_MODE_OUTPUT);
    gpio_set_direction(1, GPIO_MODE_OUTPUT);
    gpio_set_direction(3, GPIO_MODE_OUTPUT);
    gpio_set_direction(21, GPIO_MODE_OUTPUT);
    gpio_set_direction(19, GPIO_MODE_OUTPUT);
    gpio_set_direction(18, GPIO_MODE_OUTPUT);
    gpio_set_direction(5, GPIO_MODE_OUTPUT);

    while (true)
    {
        gpio_set_level(23, 1);
        usleep(ON_time);
        gpio_set_level(23, 0);
        usleep(OFF_time);
        gpio_set_level(22, 1);
        usleep(ON_time);
        gpio_set_level(22, 0);
        usleep(OFF_time);
        gpio_set_level(1, 1);
        usleep(ON_time);
        gpio_set_level(1, 0);
        usleep(OFF_time);
        gpio_set_level(3, 1);
        usleep(ON_time);
        gpio_set_level(3, 0);
        usleep(OFF_time);
        gpio_set_level(21, 1);
        usleep(ON_time);
        gpio_set_level(21, 0);
        usleep(OFF_time);
        gpio_set_level(19, 1);
        usleep(ON_time);
        gpio_set_level(19, 0);
        usleep(OFF_time);
        gpio_set_level(18, 1);
        usleep(ON_time);
        gpio_set_level(18, 0);
        usleep(OFF_time);
        gpio_set_level(5, 1);
        usleep(ON_time);
        gpio_set_level(5, 0);
        usleep(OFF_time);
    }
}