#include "LedStrip.h"

LedStrip::LedStrip() : strip(LEDS_COUNT, LEDS_PIN) {}

void LedStrip::begin() {
    strip.begin();
    strip.setBrightness(MAX_BRIGHTNESS);
}

void LedStrip::setPixel(uint16_t index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index >= LEDS_COUNT) return;
    uint32_t color = ((uint32_t)red << 16) | ((uint32_t)green << 8) | blue;
    strip.setLedColorData(index, color);
}

void LedStrip::show() {
    strip.show();
}
