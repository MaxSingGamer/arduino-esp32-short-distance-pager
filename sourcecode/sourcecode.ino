#include <SoftwareWire.h>
#include <DS3231.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans18pt7b.h>
#include <Fonts/FreeSans12pt7b.h>

SoftwareSerial SWSerial(2,3);//(RX,TX)
SoftwareWire SWWire(4,5);//(SDA,SCL)
//DS3231 DS(4,5);//(SDA,SCL)
DS3231 myRTC;
Adafruit_SSD1306 OLED(128,64);///(X,Y)

void setup() {
  Wire.begin();
  SWSerial.begin(115200);
  Serial.begin(115200);
  OLED.begin(SSD1306_SWITCHCAPVCC,0x3C);
  OLED.clearDisplay();
  OLED.setTextSize(1);
  OLED.setTextColor(WHITE);

}

void loop() {
  static const unsigned char PROGMEM Displ[] = {
    0x00,0x00,0x13,0x00,0x3F,0x00,0x37,0xFE,0x37,0xFF,0x3E,0x67,0x7C,0x66,0x7B,0x6C,
    0xF3,0x6C,0xF7,0x6E,0x36,0x66,0x36,0x66,0x3C,0x66,0x3C,0x67,0x38,0x63,0x33,0xE0
  };
  OLED.drawBitmap(0, 0, Displ, 16, 16, WHITE);
  OLED.display();
  
}
