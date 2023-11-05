# 64030165 Ratchanon Busaracome

## โปรแกรมไฟวิ่ง รุ่นที่ 1
ไฟกระพริบ จาก LED1 - LED8 ตามลำดับ โดยกระพริบติดและดับครั้งละ 1 วินาที
```c++
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h" // เพื่อการใช้งาน digital output (GPIO)

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
        sleep(1);
        gpio_set_level(23, 0);
        sleep(1);
        gpio_set_level(22, 1);
        sleep(1);
        gpio_set_level(22, 0);
        sleep(1);
        gpio_set_level(1, 1);
        sleep(1);
        gpio_set_level(1, 0);
        sleep(1);
        gpio_set_level(3, 1);
        sleep(1);
        gpio_set_level(3, 0);
        sleep(1);
        gpio_set_level(21, 1);
        sleep(1);
        gpio_set_level(21, 0);
        sleep(1);
        gpio_set_level(19, 1);
        sleep(1);
        gpio_set_level(19, 0);
        sleep(1);
        gpio_set_level(18, 1);
        sleep(1);
        gpio_set_level(18, 0);
        sleep(1);
        gpio_set_level(5, 1);
        sleep(1);
        gpio_set_level(5, 0);
        sleep(1);
    }
}
```
## โปรแกรมไฟวิ่ง รุ่นที่ 2
โดยได้ผลลัพธ์เหมือนโปรแกรมรุ่นที่ 1 แต่สร้างตัวแปร ON_time และ OFF_time ให้มีค่าเท่ากับ 1000000 และใช้การหน่วงเวลาโดยใช้ฟังก์ชัน usleep แทน และใช้ค่า ON_time และ OFF_time แทนจะกรอกตัวเลข
```c++
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

```
## โปรแกรมไฟวิ่ง รุ่นที่ 3
โดยโปรแกรมก็จะทำเหมือนโปรแกรมไฟวิ่งรุ่นที่ 1 แต่ ทำให้การเขียนโค้ดง่ายต่อการแก้โดยใช้ for loop มาใช้ โดยการกำหนด Array ให้มีขนาด 8 และกำหนดขาที่ต้องการ
โดยเขียน for loop ในการ reset pin และกำหนด direction 
```c++
    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include "driver/gpio.h"

    uint32_t ON_time = 500000;
    uint32_t OFF_time = 0;

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
                ledNum = 0;
        }
    }

```
## [Challenge](./Challenge.md)
