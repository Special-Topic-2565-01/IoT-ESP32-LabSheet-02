 #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include "driver/gpio.h"

    void app_main(void)
    {
        gpio_reset_pin(22);
        gpio_set_direction(22, GPIO_MODE_OUTPUT);

        while (true)
        {
            gpio_set_level(22, 1);
            usleep(500000);
            gpio_set_level(22, 0);
            usleep(500000);
        }
    }
