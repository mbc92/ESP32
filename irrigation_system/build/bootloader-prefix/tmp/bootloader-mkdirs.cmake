# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/chris/esp/esp-idf/components/bootloader/subproject"
  "/Users/chris/esp32-repo/ESP32/irrigation_system/build/bootloader"
  "/Users/chris/esp32-repo/ESP32/irrigation_system/build/bootloader-prefix"
  "/Users/chris/esp32-repo/ESP32/irrigation_system/build/bootloader-prefix/tmp"
  "/Users/chris/esp32-repo/ESP32/irrigation_system/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/chris/esp32-repo/ESP32/irrigation_system/build/bootloader-prefix/src"
  "/Users/chris/esp32-repo/ESP32/irrigation_system/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/chris/esp32-repo/ESP32/irrigation_system/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/chris/esp32-repo/ESP32/irrigation_system/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
