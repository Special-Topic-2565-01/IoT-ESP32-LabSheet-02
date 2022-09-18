# IoT-ESP32-LabSheet-02
# โปรแกรมไฟวิ่ง 8 ดวง
## [(กลับไปหน้าที่แล้ว)](./Chasing-LED-V2.md

## 5. ปรับปรุงโปรแกรมวงจรไฟวิ่ง 8 ดวง  รุ่นที่ 3

จากการทดลองที่ผ่านมา จะเห็นว่าในส่วนของการทำซ้ำ ทั้งการกำหนดทิศทางและการรีเซ็ตขา digital output รวมทั้งใน while loop เป็นการเขียนโปรแกรมซ้ำ ๆ กันเป็นจำนวนมาก ซึ่งอาจจะมีที่ผิด หรือยากแก่การแก้ เช่นในกรณีต้องการเปลี่ยนตำแหน่งขา เป็นต้น

เนื่องจากเป็นการทำซ้ำจำนวนมากถึง 8 รอบ โดยสิ่งที่แตกต่างกันในแต่ละบรรทัดมีเพียงแค่ตำแหน่งขาของ digital output เท่านั้น ดังนั้นในการปรับปรุงโปรแกรมรอบนี้ เราจะใช้ array มาช่วยเก็บตำแหน่งขาแล้ววนลูปด้วยตัวนับ โดยยังคงใช้ฟังก์ชันเดิมในการทำงาน
   

1. เพิ่ม array สำหรับเก็บข้อมูลพร้อมกำหนดค่าเริ่มต้น (ในวงเล็บปีกกา)

```c
    uint8_t LEDIO[8] = { 23, 22, 1, 3, 21, 19, 18, 5 };
```
2. เปลี่ยนฟังก์ชัน `gpio_reset_pin(...);` ที่เรียกซ้ำ 8 รอบให้เป็น for loop ดังต่อไปนี้

```c
	for (uint8_t i = 0; i < 8; i++)
	{
		gpio_reset_pin(LEDIO[i]);
	}
```

3. เปลี่ยนฟังก์ชัน `gpio_set_direction(..., ...);` ที่เรียกซ้ำ 8 รอบให้เป็น for loop ดังต่อไปนี้

```c
	for (uint8_t i = 0; i < 8; i++)
	{
		gpio_set_direction(LEDIO[i], GPIO_MODE_OUTPUT);
	}
```
4. เพิ่มตัวแปรสำหรับ index  ของ array ไว้นอก while loop   


```c
	uint8_t ledNum = 0;
```
5. ใน while loop ให้เปลี่ยนโปรแกรมที่กำหนดสถานะของ digital output เป็น code ดังต่อไปนี้

```c
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
```

6. Build โปรแกรม ถ้ามีที่ผิดให้แก้ไขให้ถูกต้อง จากนั้นทดลองรันโปรแกรม สังเกตุสิ่งที่เกิดขึ้น

---
***โปรแกรมสมบูรณ์ของไฟวิ่ง 8 ดวง รุ่นที่ 3***
``` c
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
---

## [6. Challenge (คลิกเพื่อเข้าสู่ Challenge)](./Chasing-LED-Challenge.md)