# IoT-ESP32-LabSheet-02
# โปรแกรมไฟวิ่ง 8 ดวง
## [(กลับไปหน้าที่แล้ว)](./chasing_led.md)

## 4. ปรับปรุงโปรแกรมวงจรไฟวิ่ง 8 ดวง 

จากการทดลองที่ผ่านมา เราจะแก้ไขโปรแกรมได้ค่อนข้างลำบาก เนื่องจากเมื่อต้องการปรับเปลี่ยนค่าบางอย่าง เช่นความเร็วในการวิ่งของ LED เราต้องแก้ไขค่า delay เป็นจำนวนหลายที่มาก และถ้าต้องการเปลี่ยนตำแหน่ง Digital Output ของ LED ก็ต้องแก้ไขโปรแกรมหลายที่เช่นกัน

### 4.1 ปรับความเร็วในการวิ่งของ LED
1. สมมติว่าเราจะแบ่งเวลาในการวิ่งของ LED ออกเป็น 2 จังหวะคือช่วง ON และ OFF ดังนั้นเราต้องสร้างตัวแปรขึ้นมา 2 ตัวเพื่อเก็บเวลาดังกล่าว ให้แก้โปรแกรมโดยการเพิ่มตัวแปรก่อนฟังก์ชัน `app_main` ดังนี้

```c
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"                        // เพื่อการใช้งาน digital output (GPIO)

uint32_t ON_time = 1000000;  // ตัวแปรสำหรับเก็บค่าเวลาช่วง LED ติดสว่าง
uint32_t OFF_time = 1000000;  // ตัวแปรสำหรับเก็บค่าเวลาช่วง LED ดับ


void app_main(void)
```

2. ใน while loop ให้เปลี่ยนค่าตัวเลขใน parameter ของ `usleep()` เป็น `ON_time` และ `OFF_time` ตามตำแหน่งของการ delay 


```c
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
```

3. เราสามารถเพิ่มความเร็วในการวิ่ง (ลดเวลาในการ delay ให้น้อยกว่า 1 วินาที) โดยการใช้ฟังก์ชัน `usleep` ซึ่งจะรับค่าที่มีคาบเวลาเป็นไมโครวินาที ดังนั้นเมื่อเปลี่ยน `sleep` ใน while loop เป็น `usleep` และเปลี่ยนช่วงเวลาให้กลายเป็นหน่วยไมโครวินาที  (`ON_time = 1000000` และ `OFF_time = 1000000` ตามลำดับ) ก็จะพบว่าความเร็วในการวิ่งจะไม่เปลี่ยนแปลง (1 วินาที = 1000000 ไมโครวินาที) 

```c
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"

uint32_t ON_time = 1000000; // เปลี่ยนจาอ ON_time = 1 วินาที เป็น ON_time = 1000000 ไมโครวินาที LED จะวิ่งเร็วเท่าเดิม
uint32_t OFF_time = 1000000; // เปลี่ยนจาอ OFF_time = 1 วินาที เป็น OFF_time = 1000000 ไมโครวินาที LED จะวิ่งเร็วเท่าเดิม

void app_main(void)
{
    gpio_reset_pin(23);
    // อีก 7 บรรทัดไม่ได้แสดงไว้

    gpio_set_direction(23, GPIO_MODE_OUTPUT);
    // อีก 7 บรรทัดไม่ได้แสดงไว้

    while (true)
    {
        gpio_set_level(23, 1);
        usleep(ON_time);    // เปลี่ยนจาก sleep เป็น usleep
        gpio_set_level(23, 0);
        usleep(OFF_time);
        // อีก 7 LED ไม่ได้แสดงไว้
    }
}
```
4. ทดลองเปลี่ยนเวลา `ON_time = 500000;` (ห้าแสน) และ `OFF_time = 500000;` (ห้าแสน) แล้วลองรันโปรแกรมว่ามีการเปลี่ยนแปลงอย่างไร

---

5. จะเห็นว่า LED ยังคงวิ่งไม่ต่อเนื่อง ทั้งนี้เนื่องมาจากเราได้ทำการหน่วงเวลาในจังหวะที่ LED ดับเอาไว้ด้วย (เกิดจากปรับปรุง source code ของไฟกระพริบดวงเดียว ที่ต้องมีช่วงหน่วงเวลาของการดับให้เห็น) ดังนั้นให้แก้เวลาใหม่ โดยให้ `OFF_time` = 0  แล้วลองรันโปรแกรม สังเกตุว่ามีการเปลี่ยนแปลงอย่างไรบ้าง

--- 
***โปรแกรมสมบูรณ์ของไฟวิ่ง 8 ดวง รุ่นที่ 2***
``` c
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

--- 



## [5. ปรับปรุงโปรแกรมวงจรไฟวิ่ง 8 ดวง รุ่นที่ 3 (คลิกเพื่อเข้าสู่การทดลอง)](./Chasing-LED-V3.md)
