
# HW

```
PLATFORM: Espressif 8266 (4.2.1) > Espressif Generic ESP8266 ESP-07S
HARDWARE: ESP8266 80MHz, 80KB RAM, 4MB Flash
PACKAGES:
 - framework-arduinoespressif8266 @ 3.30102.0 (3.1.2)
 - tool-esptool @ 1.413.0 (4.13)
 - tool-esptoolpy @ 1.30000.201119 (3.0.0)
 - toolchain-xtensa @ 2.100300.220621 (10.3.0)
```

https://en.wikipedia.org/wiki/ESP8266

https://www.espressif.com/en/products/devkits
:   DevKits

https://nurdspace.nl/ESP8266#AT_Commands
:   AT commands

https://mischianti.org/esp-07-high-resolution-pinout-and-specs/

https://www.esp8266.com/wiki/doku.php?id=getting-started-with-the-esp8266
:   Getting Started with ESP8266. Basic wiring. Talk to me, baby.

https://arduino.ua/prod1444-wi-fi-modyl-esp8266-versiya-esp-07
:   Reviews.

# ESP8266

https://www.espressif.com/en/products/socs/esp8266ex/resources

# SDK

https://docs.platformio.org/en/latest/boards/espressif8266/esp07s.html
:   Espressif Generic ESP8266 ESP-07S PlatformIO target.

https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/api-reference/index.html
:   API Reference.  ESP8266 RTOS SDK Programming Guide

https://github.com/espressif/ESP8266_NONOS_SDK

# Pinout

EN (CH_PD): V3.3 for chip to operate.
IO15 is DOWN via 12k by the board.
IO0: UP/floating is FLASH Boot mode; DOWN is UART Download mode. Default is UP via 12k pullup. Need to short down for flashing.
IO2: Default is UP via 12k pullup. No need to configure.

https://mischianti.org/esp-12-esp-07-esp8266-programming-board-and-breadboard-adapter/
:   breadboard adapter, UART connection schema.

https://lastminuteengineers.com/esp8266-pinout-reference
:   ESP8266 Pinout Reference

https://github.com/esp8266/esp8266-wiki/wiki/Pin-definition
:   ESP8266EX chip pinout is something like this.

```
74880 - baund rate of boot firmware.
115200 - baund rate of Ai-Thinker welcome message.
921600
```

Flashing boot log??:

```
ets Jan  8 2013,rst cause:1, boot mode:(1,6)
```

Regular boot log:

```
ets Jan  8 2013,rst cause:1, boot mode:(3,6)

load 0x40100000, len 1856, room 16
tail 0
chksum 0x63
load 0x3ffe8000, len 776, room 8
tail 0
chksum 0x02
load 0x3ffe8310, len 552, room 8
tail 0
chksum 0x79
csum 0x79

2nd boot version : 1.5
  SPI Speed      : 40MHz
  SPI Mode       : DIO
  SPI Flash Size & Map: 32Mbit(512KB+512KB)
jump to run user1 @ 1000

rf cal sector: 1017
rf[112] : 00
rf[113] : 00
rf[114] : 01

SDK ver: 1.5.4.1(39cb9a32) compiled @ Jul  1 2016 20:04:35
phy ver: 972, pp ver: 10.1
```

# Flashing

https://www.espressif.com/en/support/download/other-tools
:   Flash Download Tools.

https://docs.espressif.com/projects/esptool/en/latest/esp8266/esptool/flashing-firmware.html
:   Esptool is used under the hood of many development frameworks for Espressif SoCs, such as ESP-IDF, Arduino, or PlatformIO

https://docs.espressif.com/projects/esptool/en/latest/esp8266/troubleshooting.html
:   Troubleshooting.

https://github.com/espressif/esptool
:   Espressif SoC serial bootloader utility.

put the esp8266 into programming mode (switch + reset), upload the sketch, turn off programming mode

The EN (a.k.a. CH_PD or Chip Power Down) pin is the enable pin for the ESP8266, pulled high by
default. When pulled HIGH, the chip is enabled; when pulled LOW, the chip is disabled.

https://www.best-microcontroller-projects.com/esp-01-programming.html
:   Getting Started with ESP 01 Programming

https://forum.arduino.cc/t/esp-07-project-based-on-esp-07s-how-to-configure-flash/563654
:   how to configure flash?

https://mischianti.org/esp12-esp07-esp8266-flash-pinout-specs-and-arduino-ide-configuration-6/
:   esp12 esp07 (esp8266): flash, pinout, specs and Arduino IDE configuration – 6

https://www.instructables.com/ESP8266-07-Programmer-With-Arduino-Nano/
:   ESP8266-07 Programmer With Arduino Nano

https://techniccontroller.com/how-to-esp8266-programming-with-arduino-ide/
:   How-To: ESP8266 Programming with Arduino IDE

https://www.instructables.com/Arduino-UNO-ESP8266-WiFi-Module/
:   Arduino UNO + ESP8266 WiFi Module

https://forum.arduino.cc/t/esp8266-flash-programming-without-ide/572301
:   ESP8266 flash programming without IDE?

https://community.platformio.org/t/cannot-use-esp07s-board-error-unknown-board-id-esp07s/30841/8
:   I think the 1Mb limit is for program code. You can have a maximum of 1Mb worth of application code.
    The remaining 3Mb can be used for “spiffs” or “littlefs” file systems where you should be able to
    store your OTA updates.

https://github.com/esp8266/esp8266-wiki/wiki/Uploading
:   To upload to the module, configure the following pins.

https://github.com/esp8266/esp8266-wiki/wiki/Boot-Process
:   Boot Process.

https://github.com/esp8266/source-code-examples/blob/master/blinky/user/user_main.c
:   Examples of code for the ESP8266.


# CH340 USB to TTL (Serial) HW 597 Converter Module

https://electrobes.com/product/ch-340-usb-to-ttl-serial-hw-597-converter-module/
:   3.3V-5V TTL voltages
    Converts TTL logic levels to computer RS232 levels
    Power supplies: 5V, 3.3V, GND (min)
    RX (3.3V-5V)
    TX (3.3V-5V)
    Features:
    With the supplied jumper you can configure the module for 5V or 3.3V. Without the jumper, the module is automatically powered with 3.3V. For 5V you have to put the jumper between the Vcc and 5V.
    If you want to change the voltage, first disconnect it from a computer so that there is no voltage on the module.

https://hobbycomponents.com/adapters/1145-ch340-usb-to-serial-ttl-adapter-with-53v-jumper
:   It also has the additional feature of being able to select 3.3V*/5V TTL levels by linking the VCC
    pin to either the 3.3V pin or 5V pin using the supplied jumper.

    Note: This module is not suitable for use with ESP modules. Please see alternative item HCMODU0076 instead.

https://www.wch.cn/download/CH341SER_EXE.html
:   USB to serial port Windows driver and DLL library, support CH340 and CH341, including instructions
    for setting non-standard baud rate, support USB to UART 3-wire and 9-wire SERIAL serial port.
    Support 32/64-bit Windows 11/10/8.1/8/7/VISTA/XP, SERVER 2022/2019/2016/2012/2008/2003,
    2000/ME/98, and pass Microsoft digital signature certification, which is convenient for product
    application software packaging and integration.

https://voron.ua/en/catalog/035673--programmator_hw-597_usb_to_ttl_ch340_konverter
:   Может, кому пригодится, а то мне показалось не очевидным: перемычку на выбор питания ставить
    обязательно, иначе устройство не опознается по USB. Даже несмотря на то, что на VCC питание
    присутствует и без нее.

    И при питании 3,3В работает с модемом то уровню 2,8В

https://stackoverflow.com/questions/4999280/how-to-send-characters-in-putty-serial-communication-only-when-pressing-enter
:   Turning on ECHO mode & local editing in Putty.
    4.3.8 ‘Local echo’
    4.3.9 ‘Local line editing’

https://en.wikipedia.org/wiki/Tera_Term
:   `scoop install teraterm` doesn't support COM on Windows.

https://www.reddit.com/r/esp32/comments/svoejm/a_question_about_ch340/
:   I want to use a ch340 as a USB-UART converter for my custom esp32 boards.

https://www.reddit.com/r/esp8266/comments/96f323/comment/ee0vwn8/
:   On the device I have HW-597 on the back, if the jumper is on the VCC - 3.3v the level of the TX
    line is 3.3v. If the jumper is not installed the TX level is still 3.3v. If the jumper is moved to
    5V-VCC then the TX level is 5v. This was confusing since couldn't see how one would connect the
    voltage pin to the device with the jumper installed until I read in this area that there isn't
    enough current to properly power a device, thus it's not expected for the 5 or 3.3 volt pins to be
    connected to the device.

* https://stackoverflow.com/questions/60263867/problem-with-uploading-bin-file-to-esp8266
* https://www.reddit.com/r/esp32/comments/svoejm/a_question_about_ch340/

# Crypto libs

https://github.com/rweather/arduinolibs
:   Arduino Cryptography Library, has low memory footprint implementations of AES128: AESTiny128, AESSmall128. C++, not packages as PlatformIO.

https://rweather.github.io/arduinolibs/classAESTiny128.html
:   AES block cipher with 128-bit keys and tiny memory usage. More...

https://rweather.github.io/arduinolibs/crypto.html
:   Arduino Cryptography Library


Other projects:

https://registry.platformio.org/libraries/intrbiz/Crypto
:   This is a minimal, lightweight crypto library for the ESP8266 IOT device.

https://registry.platformio.org/libraries/obsttube/CryptoAES_CBC
:   Forked from rweather/arduinolibs and modified to work not only on Arduino, but on ESP8266 as well...

https://registry.platformio.org/libraries/suculent/AESLib
:   AES encryption. Easy-to-use cross-platform AES implementation (128-bit CBC) for low-memory conditions

https://github.com/suculent/thinx-aes-lib
:   AES wrapper for ESP8266/ESP32/Arduino/nRF5x




