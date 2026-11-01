#pragma once
#include <Arduino.h>
#include <ESP32_WS2812_Lib.h>
#include "config.h"

class LedStrip {
public:
    LedStrip();
    void begin();
    void setPixel(uint16_t index, uint8_t red, uint8_t green, uint8_t blue);
    void show();
private:
    ESP32_WS2812 strip;
};
