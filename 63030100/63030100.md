# รายงาน Labsheet-02

## [63030100 นางสาวอภัสสร หารไกร]

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


https://youtube.com/shorts/dundf6ItzCo?feature=share


---
## การทดลองที่ 2. การทดลองปรับเปลี่ยนเวลาสำหรับไฟกระพริบ

### Code
```
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
    gpio_set_direction(1, GPIO_MODE_OUTPUT );
    gpio_set_direction(3, GPIO_MODE_OUTPUT );
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


https://youtube.com/shorts/i-PDmag2dVI?feature=share


---
## การทดลองที่ 3. วงจรไฟวิ่ง 8 ดวงและการเขียนโปรแกรมควบคุม

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


https://youtube.com/shorts/BaT6eTphkqQ?feature=share


---
## การทดลองที่ 4. ปรับปรุงโปรแกรมวงจรไฟวิ่ง 8 ดวง

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
    }
```
### Video output


https://youtube.com/shorts/8qCwY9G4lcg?feature=share


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


https://youtube.com/shorts/7M4wcuYwNhA?feature=share


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


https://youtube.com/shorts/puVxq26Rs1o?feature=share


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
    }
```
### Video output


https://youtube.com/shorts/8qCwY9G4lcg?feature=share


---
## ขยายออก

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


https://youtube.com/shorts/7M4wcuYwNhA?feature=share


---
## ยุบเข้า

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


https://youtube.com/shorts/7M4wcuYwNhA?feature=share


---
