#pragma once
#include "LedStrip.h"

class Matrix {
public:
    Matrix();
    void begin(LedStrip& ledStrip, uint16_t matrixIndex);
    void clear();
    void fill(uint8_t red, uint8_t green, uint8_t blue);
    void setPixel(uint16_t localIndex, uint8_t red, uint8_t green, uint8_t blue);
    void show();
private:
    LedStrip* ledStrip;
    uint16_t offset;
};
