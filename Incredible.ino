#include <SPI.h>
#include "arduboy.h"
#include "IncredibleBitmaps.h"
#include "music.h"

Arduboy display;

uint8_t buttons;
uint8_t frame = 0;
uint16_t scroll = 110 << 4;

void setup()
{
    SPI.begin();
    display.start();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.tune_playscore(trendy);
}

void loop() {
    if(scroll >= 1) {
      display.fillDisplay();
      scroll--;
    }
    
    if(frame == 0) {
      display.drawBitmap(scroll >> 4, 0, incredible1, 128, 64, 1);
    }
    else {
      display.drawBitmap(scroll >> 4, 0, incredible2, 128, 64, 1);
    }
    
    display.display();
    
    frame ^= 1;
    
    if(!display.tune_playing) {display.tune_playscore(trendy);}
    
    delay(4);
}
