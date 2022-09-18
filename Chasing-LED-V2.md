# IoT-ESP32-LabSheet-02
# โปรแกรมไฟวิ่ง 8 ดวง
## [(กลับไปหน้าที่แล้ว)](./chasing_led.md)

## 4. ปรับปรุงโปรแกรมวงจรไฟวิ่ง 8 ดวง 

จากการทดลองที่ผ่านมา เราจะแก้ไขโปรแกรมได้ค่อนข้างลำบาด เนื่องจากเมื่อต้องการปรับเปลี่ยนค่าบางอย่าง เช่นความเร็วในการวิ่งของ LED เราต้องแก้ไขค่า delay เป็นจำนวนหลายที่มาก และถ้าต้องการเปลี่ยนตำแหน่ง Digital Output ของ LED ก็ต้องแก้ไขโปรแกรมหลายที่เช่นกัน

### 4.1 ปรับความเร็วในการวิ่งของ LED
1. สมมติว่าเราจะแบ่งเวลาในการวิ่งของ LED ออกเป็น 2 จังหวะคือช่วง ON และ OFF ดังนั้นเราต้องสร้างตัวแปรขึ้นมา 2 ตัวเพื่อเก็บเวลาดังกล่าว ให้แก้โปรแกรมโดยการเพิ่มตัวแปรก่อนฟังก์ชัน `app_main` ดังนี้

```c
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"                        // เพื่อการใช้งาน digital output (GPIO)

uint32_t ON_time = 1;  // ตัวแปรสำหรับเก็บค่าเวลาช่วง LED ติดสว่าง
uint32_t OFF_time = 1;  // ตัวแปรสำหรับเก็บค่าเวลาช่วง LED ดับ


void app_main(void)
```

2. ใน while loop ให้เปลี่ยนค่าตัวเลขใน parameter ของ `usleep()` เป็น `ON_time` และ `OFF_time` ตามตำแหน่งของการ delay 


```c
    while (true)
    {
        gpio_set_level(23, 1);
        sleep(ON_time);
        gpio_set_level(23, 0);
        sleep(OFF_time);
        gpio_set_level(22, 1);
        sleep(ON_time);
        gpio_set_level(22, 0);
        sleep(OFF_time);
        gpio_set_level(1, 1);
        sleep(ON_time);
        gpio_set_level(1, 0);
        sleep(OFF_time);
        gpio_set_level(3, 1);
        sleep(ON_time);
        gpio_set_level(3, 0);
        sleep(OFF_time);
        gpio_set_level(21, 1);
        sleep(ON_time);
        gpio_set_level(21, 0);
        sleep(OFF_time);
        gpio_set_level(19, 1);
        sleep(ON_time);
        gpio_set_level(19, 0);
        sleep(OFF_time);
        gpio_set_level(18, 1);
        sleep(ON_time);
        gpio_set_level(18, 0);
        sleep(OFF_time);
        gpio_set_level(5, 1);
        sleep(ON_time);
        gpio_set_level(5, 0);
        sleep(OFF_time);
    }
```

3. จากหัวข้อที่ 1 เราสามารถเพิ่มความเร็วในการวิ่ง (ลดเวลาในการ delay ให้น้อยกว่า 1 วินาทีโดยการใช้ฟังก์ชัน `usleep`) ใน while loop ให้เปลี่ยน `sleep` เป็น `usleep` และเปลี่ยนเวลาเป็น  `ON_time = 1000000` และ `OFF_time = 1000000` ตามลำดับ 

```c
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"                        // เพื่อการใช้งาน digital output (GPIO)

uint32_t ON_time = 1000000; // เปลี่ยนจาอ ON_time = 1 วินาที เป็น ON_time = 1000000 ไมโครวินาที 
                            // LED จะวิ่งเร็วเท่าเดิม
uint32_t OFF_time = 1000000; // เปลี่ยนจาอ OFF_time = 1 วินาที เป็น OFF_time = 1000000 ไมโครวินาที 
                            // LED จะวิ่งเร็วเท่าเดิม


void app_main(void)
{
    gpio_reset_pin(23);
    // อีก 7 บรรทัดไม่ได้แสดงไว้

    gpio_set_direction(23, GPIO_MODE_OUTPUT);
    // อีก 7 บรรทัดไม่ได้แสดงไว้

    while (true)
    {
        gpio_set_level(23, 1);
        usleep(ON_time);
        gpio_set_level(23, 0);
        usleep(OFF_time);
        // อีก 7 LED ไม่ได้แสดงไว้
    }
}
```


