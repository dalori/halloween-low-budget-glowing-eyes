#include "LedStrip.h"

LedStrip::LedStrip() {}

void LedStrip::begin() {
    FastLED.addLeds<WS2812, LEDS_PIN, GRB>(leds, LEDS_COUNT);
    FastLED.setBrightness(MAX_BRIGHTNESS);
    FastLED.clear(true);
}

void LedStrip::setPixel(uint16_t index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index >= LEDS_COUNT) return;
    leds[index].setRGB(red, green, blue);
}

void LedStrip::show() {
    FastLED.show();
}