# สวัสดีครับ 63030031 ณัฐวุฒิ อุดเสริม

## การทดลองที่ 1

```c
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"                        // เพื่อการใช้งาน digital output (GPIO)

void app_main(void)
{
    gpio_reset_pin(22);                         // รีเซ็ตสถานะของขาหมายเลข 22
    gpio_set_direction(22, GPIO_MODE_OUTPUT);   // กำหนดให้ขาหมายเลข 22 เป็น digital output

    while (true)                                // while (true) = วนรอบไม่มีที่สิ้นสุด
    {
        gpio_set_level(22, 1);                  // สั่งให้ LED ติด
        usleep(500000);                         // หน่วงเวลา 0.5 วินาที
        gpio_set_level(22, 0);                  // สั่งให้ LED ดับ
        usleep(500000);                         // หน่วงเวลา 0.5 วินาที
    }
}
```
ลิงค์วีดีโอการทดลองที่ 1 : https://youtu.be/1YTbJLF1pSc

# 

## การทดลองที่ 2
```c
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"                        // เพื่อการใช้งาน digital output (GPIO)

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
ลิงค์วีดีโอการทดลองที่ 2 : https://youtu.be/6Vz7U6Fxx5Y
# 

## การทดลองที่ 3
```c
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"

uint32_t ON_time = 500000;
uint32_t OFF_time = 500000;


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
ลิงค์วีดีโอการทดลองที่ 3 : https://youtu.be/kuA_FNj4njw
# 

## การทดลองที่ 4
```c
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
ลิงค์วีดีโอการทดลองที่ 4 : https://youtu.be/3o5rxLbf-hw
# 

## ชาเลนท์ 1
```c
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
        ledNum++;
        if (ledNum == 8)
        {
            for (int8_t i = 7; i >= 0 ; i--)
            {
                gpio_set_level(LEDIO[i], 1);
                usleep(ON_time);
                gpio_set_level(LEDIO[i], 0);
            }
            ledNum = 0;
        }
    }
}

```
ลิงค์วีดีโอชาเลนท์ 1 : https://youtu.be/4_kibuCmOMw
# 

## ชาเลนท์ 2
```c
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

        ledNum++;
        if (ledNum == 8)
        {
            for (int8_t i = 7; i >= 1 ; i--)
            {
                gpio_set_level(LEDIO[i], 0);
                usleep(ON_time);

            }
            ledNum = 0;
        }
    }
}

```
ลิงค์วีดีโอชาเลนท์ 2 : https://youtu.be/cmvICDJumfc
# 

## ชาเลนท์ 3
```c
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"

uint32_t ON_time = 500000;
uint32_t OFF_time = 0;

uint8_t LEDIO[8] = { 3, 1, 22, 23, 21, 19, 18, 5 };

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
        gpio_set_level(LEDIO[4+ledNum], 1);
        usleep(ON_time);
        gpio_set_level(LEDIO[ledNum], 0);
        gpio_set_level(LEDIO[4+ledNum], 0);
        usleep(OFF_time);
        ledNum++;
        if (ledNum == 4)
        {

            ledNum = 0;
        }

    }
}

```
ลิงค์วีดีโอชาเลนท์ 3 : https://youtu.be/jDKmrDrzKgQ
# 

## ชาเลนท์ 4
```c
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"

uint32_t ON_time = 500000;
uint32_t OFF_time = 0;

uint8_t LEDIO[8] = { 23, 22, 1, 3, 5, 18, 19, 21 };

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
        gpio_set_level(LEDIO[4+ledNum], 1);
        usleep(ON_time);
        gpio_set_level(LEDIO[ledNum], 0);
        gpio_set_level(LEDIO[4+ledNum], 0);
        usleep(OFF_time);
        ledNum++;
        if (ledNum == 4)
        {

            ledNum = 0;
        }

    }
}

```
ลิงค์วีดีโอชาเลนท์ 4 : https://youtu.be/91yW3WkgwA0
# 