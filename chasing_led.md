# IoT-ESP32-LabSheet-02
# โปรแกรมไฟวิ่ง 8 ดวง

## 3. วงจรไฟวิ่ง 8 ดวงและการเขียนโปรแกรมควบคุม

### 3.1 รายการอุปกรณ์
1. บอร์ดทดลอง IoT KMITL FIGHT จำนวน 1 บอร์ด
2. สายต่อ USB Micro จำนวน 1 เส้น
3. สายต่อวงจรชนิด ผู้-ผู้ จำนวน 8 เส้น

### 3.2 เครื่องมือในการโปรแกรม
1. Computer หรือ Laptop ที่ติดตั้งโปรแกรม ESP-IDF ([ถ้ายังไม่ติดตั้งให้ติดตั้งตามใบงานนี้ (คลิก) ](https://github.com/Special-Topic-2565-01/ESP-IDF-Tool-setup) )

### 3.3 การประกอบวงจรสำหรับทดลอง
1. __ถอดสาย micro usb ที่ต่อระหว่างบอร์ดและคอมพิวเตอร์ออกก่อนประกอบวงจร__
2. ประกอบวงจรตามรูป

<p align="center">
<img  src="Pictures/Chaser-8-leds-connection.png" alt="วงจรไฟวิ่ง 8 ดวง" style="width:500px;" >
</p>

### 3.3 สร้างโปรเจคใหม่สำหรับไฟวิ่ง 8 ดวง

1. เปิดโปรแกรม ESP-IDF 
2. สร้างโปรเจคใหม่ ชื่อ `LED-Chasing`   ([คลิกที่นี่เพื่อดูตัวอย่างขั้นตอนการสร้างโปรเจค](https://github.com/Special-Topic-2565-01/LabSheet-01))

<p align="center">
<img  src="Pictures/new-esp-idf-project.png" alt="สร้าง project ใหม่" style="width:500px;" >
</p>

หลังจากสร้างโปรเจคใหม่จะได้หน้าจอในลักษณะนี้

<p align="center">
<img  src="Pictures/created-project.png" alt="project ใหม่" style="width:500px;" >
</p>


3. Double click ที่ main.c  ของโปรเจคใหม่ เพื่อแก้ไข source code ให้เป็นโปรแกรมไฟวิ่ง
4. ในบรรทัดที่ 4 ให้เพิ่ม 

```c
#include "driver/gpio.h" // เพื่อการใช้งาน digital output (GPIO)
```

รวมทั้งเพิ่มเติมบรรทัดคำสั่งควบคุม GPIO ให้ทำงานเป็น OUTPUT สำหรับต่อ LED จนครบ 8 ดวง

``` c
    void app_main(void)
    {

        // รีเซ็ตสถานะของ Pins
        gpio_reset_pin(23);
        gpio_reset_pin(22);
        gpio_reset_pin(1);
        gpio_reset_pin(3);
        gpio_reset_pin(21);
        gpio_reset_pin(19);
        gpio_reset_pin(18);
        gpio_reset_pin(5);

        // กำหนด Pins เป็น digital output
        gpio_set_direction(23, GPIO_MODE_OUTPUT);
        gpio_set_direction(22, GPIO_MODE_OUTPUT);
        gpio_set_direction(1, GPIO_MODE_OUTPUT);
        gpio_set_direction(3, GPIO_MODE_OUTPUT);
        gpio_set_direction(21, GPIO_MODE_OUTPUT);
        gpio_set_direction(19, GPIO_MODE_OUTPUT);
        gpio_set_direction(18, GPIO_MODE_OUTPUT);
        gpio_set_direction(5, GPIO_MODE_OUTPUT);

        // ส่วน while loop ไม่ได้แสดงในที่นี้
```

