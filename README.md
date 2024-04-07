
# HW

PLATFORM: Espressif 8266 (4.2.1) > Espressif Generic ESP8266 ESP-07S
HARDWARE: ESP8266 80MHz, 80KB RAM, 4MB Flash
PACKAGES:
 - framework-arduinoespressif8266 @ 3.30102.0 (3.1.2)
 - tool-esptool @ 1.413.0 (4.13)
 - tool-esptoolpy @ 1.30000.201119 (3.0.0)
 - toolchain-xtensa @ 2.100300.220621 (10.3.0)

https://en.wikipedia.org/wiki/ESP8266

https://www.espressif.com/en/products/devkits
  DevKits
https://nurdspace.nl/ESP8266#AT_Commands
  AT commands

https://mischianti.org/esp-07-high-resolution-pinout-and-specs/

https://www.esp8266.com/wiki/doku.php?id=getting-started-with-the-esp8266
  Getting Started with ESP8266. Basic wiring. Talk to me, baby.

# ESP8266

https://www.espressif.com/en/products/socs/esp8266ex/resources

# SDK

https://docs.platformio.org/en/latest/boards/espressif8266/esp07s.html
  Espressif Generic ESP8266 ESP-07S PlatformIO target.

https://github.com/espressif/ESP8266_NONOS_SDK

# Pinout

EN (CH_PD): V3.3 for chip to operate.
IO15 is DOWN via 12k by the board.
IO0: UP/floating is FLASH Boot mode; DOWN is UART Download mode. Default is UP via 12k pullup. Need to short down for flashing.
IO2: Default is UP via 12k pullup. No need to configure.

https://mischianti.org/esp-12-esp-07-esp8266-programming-board-and-breadboard-adapter/
  breadboard adapter, UART connection schema.

74880 - baund rate of boot firmware.
115200 - baund rate of Ai-Thinker welcome message.
921600

ets Jan  8 2013,rst cause:1, boot mode:(1,6)


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


# Flashing

https://www.espressif.com/en/support/download/other-tools
  Flash Download Tools.

https://github.com/espressif/esptool
  Espressif SoC serial bootloader utility.

put the esp8266 into programming mode (switch + reset), upload the sketch, turn off programming mode

The EN (a.k.a. CH_PD or Chip Power Down) pin is the enable pin for the ESP8266, pulled high by
default. When pulled HIGH, the chip is enabled; when pulled LOW, the chip is disabled.

https://forum.arduino.cc/t/esp-07-project-based-on-esp-07s-how-to-configure-flash/563654
  how to configure flash?

# CH340 USB to TTL (Serial) HW 597 Converter Module

https://electrobes.com/product/ch-340-usb-to-ttl-serial-hw-597-converter-module/
  3.3V-5V TTL voltages
  Converts TTL logic levels to computer RS232 levels
  Power supplies: 5V, 3.3V, GND (min)
  RX (3.3V-5V)
  TX (3.3V-5V)
  Features:
  With the supplied jumper you can configure the module for 5V or 3.3V. Without the jumper, the module is automatically powered with 3.3V. For 5V you have to put the jumper between the Vcc and 5V.
  If you want to change the voltage, first disconnect it from a computer so that there is no voltage on the module.

https://hobbycomponents.com/adapters/1145-ch340-usb-to-serial-ttl-adapter-with-53v-jumper
  It also has the additional feature of being able to select 3.3V*/5V TTL levels by linking the VCC
  pin to either the 3.3V pin or 5V pin using the supplied jumper.

  Note: This module is not suitable for use with ESP modules. Please see alternative item HCMODU0076 instead.


https://www.wch.cn/download/CH341SER_EXE.html
  USB to serial port Windows driver and DLL library, support CH340 and CH341, including instructions
  for setting non-standard baud rate, support USB to UART 3-wire and 9-wire SERIAL serial port.
  Support 32/64-bit Windows 11/10/8.1/8/7/VISTA/XP, SERVER 2022/2019/2016/2012/2008/2003,
  2000/ME/98, and pass Microsoft digital signature certification, which is convenient for product
  application software packaging and integration.

https://voron.ua/en/catalog/035673--programmator_hw-597_usb_to_ttl_ch340_konverter
  Может, кому пригодится, а то мне показалось не очевидным: перемычку на выбор питания ставить
  обязательно, иначе устройство не опознается по USB. Даже несмотря на то, что на VCC питание
  присутствует и без нее.

  И при питании 3,3В работает с модемом то уровню 2,8В

https://stackoverflow.com/questions/4999280/how-to-send-characters-in-putty-serial-communication-only-when-pressing-enter
  Turning on ECHO mode & local editing in Putty.
  4.3.8 ‘Local echo’
  4.3.9 ‘Local line editing’

https://en.wikipedia.org/wiki/Tera_Term
  `scoop install teraterm` doesn't support COM on Windows.

https://www.reddit.com/r/esp32/comments/svoejm/a_question_about_ch340/
  I want to use a ch340 as a USB-UART converter for my custom esp32 boards.

https://www.reddit.com/r/esp8266/comments/96f323/comment/ee0vwn8/
  On the device I have HW-597 on the back, if the jumper is on the VCC - 3.3v the level of the TX
  line is 3.3v. If the jumper is not installed the TX level is still 3.3v. If the jumper is moved to
  5V-VCC then the TX level is 5v. This was confusing since couldn't see how one would connect the
  voltage pin to the device with the jumper installed until I read in this area that there isn't
  enough current to properly power a device, thus it's not expected for the 5 or 3.3 volt pins to be
  connected to the device.

https://stackoverflow.com/questions/60263867/problem-with-uploading-bin-file-to-esp8266
  


