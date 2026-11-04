#pragma once
#include <Arduino.h>
#include <FastLED.h>
#include "config.h"

class LedStrip {
public:
    LedStrip();
    void begin();
    void setPixel(uint16_t index, uint8_t red, uint8_t green, uint8_t blue);
    void show();
private:
    CRGB leds[LEDS_COUNT];
};