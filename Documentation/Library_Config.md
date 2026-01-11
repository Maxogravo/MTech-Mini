# Library Config
I spent hours initially figuring out what pins each hardware feature was connected to the ESP32. Here are the correct setups for each library that the console uses:

# TFT_eSPI (Graphics Library):
#define ST7789_DRIVER

#define TFT_WIDTH  240
#define TFT_HEIGHT 320

#define TFT_OFFSET_X 0
#define TFT_OFFSET_Y 0   // only change if rotation needs it

#define TFT_SPI_PORT HSPI
#define TFT_MOSI 13
#define TFT_SCLK 14
#define TFT_MISO -1

#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  4

#define TFT_BL   21
#define TFT_BACKLIGHT_ON HIGH

#define SPI_FREQUENCY  10000000

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_GFXFF
#define SMOOTH_FONT


This should be pasted into: Arduino/libraries/TFT_eSPI/User_Setup.h
Overwrite anything else.
