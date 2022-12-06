## 63030078 นางสาววิภาดา เขวาลำธาร

*ข้อที่ 1 LED ไฟวิ่งไปวิ่งมา (ไป-กลับ)*


https://user-images.githubusercontent.com/110808292/205982883-16b85775-3f70-4c0f-8388-f5cf0cdbc8e7.mp4



```c
    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include "driver/gpio.h"

    uint32_t ON_time = 500000;
    uint32_t OFF_time = 0;

    uint8_t LEDIO[16] = { 23, 22, 1, 3, 21, 19, 18, 5, 18, 19, 21, 3, 1, 22, 23 };

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
            if (ledNum == 16)
                ledNum = 0;
        }
    }
```
##
*ข้อที่ 2 ยืด..........หด*



https://user-images.githubusercontent.com/110808292/205983074-b3996a2a-44c8-4455-81ca-67979942c143.mp4


```c
    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include "driver/gpio.h"

    uint32_t ON_time = 500000;
    uint32_t OFF_time = 0;

    uint8_t LEDIO[9] = { 23, 22, 1, 3, 21, 19, 18, 5 };

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
            if (ledNum == 9)
            {
            	for (int i = 0; i < 9; i++)
            	{
            		gpio_set_level(LEDIO[ledNum], 0);
            		usleep(ON_time);
            		ledNum--;
            	}
            }
        }
    }
```
##
*ข้อที่ 3 ขยาย..........ออก*


https://user-images.githubusercontent.com/110808292/205983380-d51edf1c-dd42-4df9-b66c-b697dae90274.mp4



```c
    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include "driver/gpio.h"

    uint32_t ON_time = 500000;
    uint32_t OFF_time = 0;

    uint8_t LEDIO[9] = { 23, 22, 1, 3, 21, 19, 18, 5 };

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
        int swcase = 0;

        while (true)
        {
        	swcase++;
        	switch (swcase){
        		case 1:
        			gpio_set_level(LEDIO[3], 1);
        			gpio_set_level(LEDIO[4], 1);
        			usleep(ON_time);
        			gpio_set_level(LEDIO[3], 0);
        			gpio_set_level(LEDIO[4], 0);
        			break;
        		case 2:
        			gpio_set_level(LEDIO[2], 1);
        			gpio_set_level(LEDIO[5], 1);
        			usleep(ON_time);
        			gpio_set_level(LEDIO[2], 0);
        			gpio_set_level(LEDIO[5], 0);
        			break;
        		case 3:
        			gpio_set_level(LEDIO[1], 1);
        			gpio_set_level(LEDIO[6], 1);
        			usleep(ON_time);
        			gpio_set_level(LEDIO[1], 0);
        			gpio_set_level(LEDIO[6], 0);
        			break;
        		case 4:
        			gpio_set_level(LEDIO[0], 1);
        			gpio_set_level(LEDIO[7], 1);
        			usleep(ON_time);
        			gpio_set_level(LEDIO[0], 0);
        			gpio_set_level(LEDIO[7], 0);
        			break;
        		case 5:
        			gpio_set_level(LEDIO[1], 1);
        			gpio_set_level(LEDIO[6], 1);
        			usleep(ON_time);
        			gpio_set_level(LEDIO[1], 0);
        			gpio_set_level(LEDIO[6], 0);
        			break;
        		case 6:
        			gpio_set_level(LEDIO[2], 1);
        			gpio_set_level(LEDIO[5], 1);
        			usleep(ON_time);
        			gpio_set_level(LEDIO[2], 0);
        			gpio_set_level(LEDIO[5], 0);
        			swcase = 0;
        			break;
        	}
        }
    }
```
##
*ข้อที่ 4 ยุบเข้า*


https://user-images.githubusercontent.com/110808292/205983428-0ab87917-5909-45f0-8436-0e4d54071473.mp4



```c
    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include "driver/gpio.h"

    uint32_t ON_time = 500000;
    uint32_t OFF_time = 0;

    uint8_t LEDIO[9] = { 23, 22, 1, 3, 21, 19, 18, 5 };

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
        int swcase = 0;

        while (true)
        {
        	swcase++;
        	switch (swcase){
        		case 1:
        			gpio_set_level(LEDIO[0], 1);
        			gpio_set_level(LEDIO[7], 1);
        			usleep(ON_time);
        			gpio_set_level(LEDIO[0], 0);
        			gpio_set_level(LEDIO[7], 0);
        			break;
        		case 2:
        			gpio_set_level(LEDIO[1], 1);
        			gpio_set_level(LEDIO[6], 1);
        			usleep(ON_time);
        			gpio_set_level(LEDIO[1], 0);
        			gpio_set_level(LEDIO[6], 0);
        			break;
        		case 3:
        			gpio_set_level(LEDIO[2], 1);
        			gpio_set_level(LEDIO[5], 1);
        			usleep(ON_time);
        			gpio_set_level(LEDIO[2], 0);
        			gpio_set_level(LEDIO[5], 0);
        			break;
        		case 4:
        			gpio_set_level(LEDIO[3], 1);
        			gpio_set_level(LEDIO[4], 1);
        			usleep(ON_time);
        			gpio_set_level(LEDIO[3], 0);
        			gpio_set_level(LEDIO[4], 0);
        			break;
        		case 5:
        			gpio_set_level(LEDIO[2], 1);
        			gpio_set_level(LEDIO[5], 1);
        			usleep(ON_time);
        			gpio_set_level(LEDIO[2], 0);
        			gpio_set_level(LEDIO[5], 0);
        			break;
        		case 6:
        			gpio_set_level(LEDIO[1], 1);
        			gpio_set_level(LEDIO[6], 1);
        			usleep(ON_time);
        			gpio_set_level(LEDIO[1], 0);
        			gpio_set_level(LEDIO[6], 0);
        			swcase = 0;
        			break;
        	}
        }
    }
```
