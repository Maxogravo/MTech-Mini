#include <TFT_eSPI.h>
#include <SPI.h>
#include <SD.h>
TFT_eSPI tft;

//SD Card Pins
#define TFT_CS    15
#define TOUCH_CS  33
#define SD_CS     5
SPIClass spiSD(VSPI);

void Splash(){
	//draw stuff
  tft.fillScreen(TFT_BLACK);
	tft.fillRect(68, 67, 43, 13, TFT_WHITE);
	tft.fillRect(110, 18, 15, 62, TFT_WHITE);
	tft.fillRect(192, 18, 15, 62, TFT_WHITE);
	tft.fillRect(111, 17, 95, 15, TFT_WHITE);
	tft.fillRect(151, 23, 14, 98, TFT_WHITE);
	tft.fillRect(207, 67, 43, 13, TFT_WHITE);
	tft.fillEllipse(57, 73, 12, 12, TFT_WHITE);
	tft.fillEllipse(260, 73, 12, 12, TFT_WHITE);
	tft.fillEllipse(158, 130, 12, 12, TFT_WHITE);
	tft.fillEllipse(158, 130, 8, 8, TFT_BLACK);
	tft.fillEllipse(260, 73, 8, 8, TFT_BLACK);
	tft.fillEllipse(57, 73, 8, 8, TFT_BLACK);
	tft.setTextColor(TFT_WHITE);
	tft.setTextSize(5);
	tft.drawString("MTECH", 84, 174);

}

void Configure() {
	//Add date time and user config here
}

void Home() {
	//draw stuff
	tft.fillScreen(TFT_BLACK);
	tft.drawRect(82, 36, 147, 147, TFT_WHITE);
	tft.drawRoundRect(3, 205, 311, 28, 9, TFT_WHITE);
	tft.setTextColor(TFT_WHITE);
	tft.setTextSize(1);
	tft.setFreeFont();
	tft.drawString("Max", 291, 215);
	tft.drawString("00:00", 16, 216);
	tft.drawString("Game Name", 133, 215);
	tft.drawRect(279, 47, 111, 121, TFT_WHITE);
	tft.drawRect(-74, 48, 111, 121, TFT_WHITE);

}

void setup() {
	//Graphics Initialisation
  tft.init();
  tft.setRotation(3); 
  tft.invertDisplay(false);

	// SD card setup
  pinMode(TFT_CS, OUTPUT);   digitalWrite(TFT_CS, HIGH);
  pinMode(TOUCH_CS, OUTPUT); digitalWrite(TOUCH_CS, HIGH);
  pinMode(SD_CS, OUTPUT);    digitalWrite(SD_CS, HIGH);
  spiSD.begin(18,19,23,SD_CS);
  SD.begin(SD_CS, spiSD, 4000000);

	//Serial
	Serial.begin(115200);

	if SD.exist("config.json"){Serial.Print("Returning User");}
	else {Configure();}

  Splash();
	delay(3000);
	Home();
}

void loop() {}
