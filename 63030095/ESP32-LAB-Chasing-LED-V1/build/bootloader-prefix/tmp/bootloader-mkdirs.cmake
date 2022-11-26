# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Espressif/frameworks/esp-idf-v4.4.2/components/bootloader/subproject"
  "C:/ESP32/ESP32-LAB2/ESP32-LAB-Chasing-LED-V1/build/bootloader"
  "C:/ESP32/ESP32-LAB2/ESP32-LAB-Chasing-LED-V1/build/bootloader-prefix"
  "C:/ESP32/ESP32-LAB2/ESP32-LAB-Chasing-LED-V1/build/bootloader-prefix/tmp"
  "C:/ESP32/ESP32-LAB2/ESP32-LAB-Chasing-LED-V1/build/bootloader-prefix/src/bootloader-stamp"
  "C:/ESP32/ESP32-LAB2/ESP32-LAB-Chasing-LED-V1/build/bootloader-prefix/src"
  "C:/ESP32/ESP32-LAB2/ESP32-LAB-Chasing-LED-V1/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/ESP32/ESP32-LAB2/ESP32-LAB-Chasing-LED-V1/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
