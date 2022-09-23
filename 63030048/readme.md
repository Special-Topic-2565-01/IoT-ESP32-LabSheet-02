Challenge 1
    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include "driver/gpio.h"

    uint32_t ON_time = 500000;
    uint32_t OFF_time = 0;
    uint8_t i = 0;

    uint8_t LEDIO[8] = { 23, 22, 1, 3, 21, 19, 18, 5 };

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
            {
            	for ( i = 0; i < 7; i++){
            		ledNum--;
            		gpio_set_level(LEDIO[ledNum], 1);
            		usleep(ON_time);
            		gpio_set_level(LEDIO[ledNum], 0);
            		usleep(OFF_time);
            	}
            	ledNum = 0;
            }
        }
    }
VDO link : https://youtu.be/O3pfaYZefko



Challenge 2
    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include "driver/gpio.h"

    uint32_t ON_time = 500000;
    uint32_t OFF_time = 500000;
    uint8_t i = 0;

    uint8_t LEDIO[8] = { 23, 22, 1, 3, 21, 19, 18, 5 };

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
            ledNum++;
            if (ledNum == 8)
            {
            	for ( i = 0; i < 7; i++){
            		ledNum--;
            		gpio_set_level(LEDIO[ledNum], 0);
            		usleep(OFF_time);
            	}
            	ledNum = 0;
            }
        }
    }
VDO clip : https://youtu.be/PmmMWFTCzJo



Challenge 3
    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include "driver/gpio.h"

    uint32_t ON_time = 500000;
    uint32_t OFF_time = 0;
    uint8_t i = 0;

    uint8_t LEDIO[8] = { 3, 1, 22, 23, 21, 19, 18, 5 };

    void app_main(void)
    {
        for (uint8_t i = 0; i < 8; i++)
        {
            gpio_reset_pin(LEDIO[i]);
            gpio_set_direction(LEDIO[i], GPIO_MODE_OUTPUT);
        }

        uint8_t ledNum = 0;

        while (true)
        {
            gpio_set_level(LEDIO[ledNum], 1);
            gpio_set_level(LEDIO[ledNum + 4], 1);
            usleep(ON_time);
            gpio_set_level(LEDIO[ledNum], 0);                                                                                                                                                                                  
            gpio_set_level(LEDIO[ledNum + 4], 0);
            usleep(OFF_time);
            ledNum++;
            if (ledNum == 4)
            {
            	for ( i = 0; i < 4; i++){
            		ledNum--;
            		gpio_set_level(LEDIO[ledNum], 1);
            		gpio_set_level(LEDIO[ledNum + 4], 1);
            		usleep(ON_time);
            		gpio_set_level(LEDIO[ledNum], 0);
            		gpio_set_level(LEDIO[ledNum + 4], 0);
            		usleep(OFF_time);
            	}
            	ledNum = 0;
            }
        }
    }
VDO clip : https://youtu.be/ZcpWVyDt31E
