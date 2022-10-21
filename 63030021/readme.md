# รายงาน Labsheet-02

## [63030021 นางสาวชุธาศิณี เมืองคำ ]

## การทดลองที่ 1. ก่อนการทดลอง

### Code
```
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

```
### Video output




https://user-images.githubusercontent.com/110808235/197129571-450c4038-a713-4c42-b66a-48bba0577694.mp4



---
## การทดลองที่ 2. การทดลองปรับเปลี่ยนเวลาสำหรับไฟกระพริบ

### Code
```
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"

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
### Video output





https://user-images.githubusercontent.com/110808235/197129756-a4c172d4-256d-4763-b445-601921fedbf3.mp4



---
## การทดลองที่ 3. วงจรไฟวิ่ง 8 ดวงและการเขียนโปรแกรมควบคุม

### Code
```
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"

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
### Video output





https://user-images.githubusercontent.com/110808235/197129960-d091dd63-8021-4f6b-b88c-1fcf75f2a3c4.mp4



---
## การทดลองที่ 4. ปรับปรุงโปรแกรมวงจรไฟวิ่ง 8 ดวง

### Code
```
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
### Video output





https://user-images.githubusercontent.com/110808235/197130047-3a9ffd2f-88c7-4d74-8b08-be441b9bcee0.mp4



---
## การทดลองที่ 5. ปรับปรุงโปรแกรมวงจรไฟวิ่ง 8 ดวง รุ่นที่3

### Code
```
   #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include "driver/gpio.h"

    uint32_t ON_time = 100000;
    uint32_t OFF_time = 100000;

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



        while (true)
        {
          for (uint8_t i = 0; i < 8; i++)
          {
            gpio_set_level(LEDIO[i], 1);
            usleep(ON_time);
            gpio_set_level(LEDIO[i], 0);
            usleep(OFF_time);

          }
          for (uint8_t i = 6; i > 0; i--)
                    {
                      gpio_set_level(LEDIO[i], 1);
                      usleep(ON_time);
                      gpio_set_level(LEDIO[i], 0);
                      usleep(OFF_time);

                    }
        }
    ''}

```
### Video output





https://user-images.githubusercontent.com/110808235/197130108-2312351b-0476-499b-a4a7-268bf1d83916.mp4


---
## 6.Challenge

## วิ่งไปสุดปลายทางแล้ววิ่งกลับ (ping-pong)

### Code
```
    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include "driver/gpio.h"

    uint32_t ON_time = 100000;
    uint32_t OFF_time = 100000;

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



        while (true)
        {
          for (uint8_t i = 0; i < 8; i++)
          {
            gpio_set_level(LEDIO[i], 1);
            usleep(ON_time);
            gpio_set_level(LEDIO[i], 0);
            usleep(OFF_time);

          }
          for (uint8_t i = 6; i > 0; i--)
                    {
                      gpio_set_level(LEDIO[i], 1);
                      usleep(ON_time);
                      gpio_set_level(LEDIO[i], 0);
                      usleep(OFF_time);

                    }
        }
    ''}

```
### Video output





https://user-images.githubusercontent.com/110808235/197130169-190bae8b-7166-4f9d-a240-3e74e60d2a8a.mp4


---
## ยืด-หด

### Code
```
    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include "driver/gpio.h"

    uint32_t ON_time = 100000;
    uint32_t OFF_time = 100000;

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

        while (true)
        {
          for (uint8_t i = 0; i < 8; i++)
          {
            gpio_set_level(LEDIO[i], 1);
            usleep(ON_time);

          }
          for (uint8_t i = 8; i > 0; i--)
           {
           gpio_set_level(LEDIO[i], 0);
           usleep(OFF_time);

           }
        }
    }
```
### Video output






https://user-images.githubusercontent.com/110808235/197130210-5ac73779-0c8b-4d95-a6b6-1673a20b58e7.mp4


---
