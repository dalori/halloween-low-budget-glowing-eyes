#include "Matrix.h"

Matrix::Matrix() : ledStrip(nullptr), offset(0) {}

void Matrix::begin(LedStrip& strip, uint16_t matrixIndex) {
    ledStrip = &strip;
    offset = matrixIndex * LEDS_PER_MATRIX;
    clear();
}

void Matrix::clear() {
    fill(0, 0, 0);
}

void Matrix::fill(uint8_t red, uint8_t green, uint8_t blue) {
    for (uint16_t i = 0; i < LEDS_PER_MATRIX; i++) setPixel(i, red, green, blue);
    show();
}

void Matrix::setPixel(uint16_t localIndex, uint8_t red, uint8_t green, uint8_t blue) {
    if (!ledStrip || localIndex >= LEDS_PER_MATRIX) return;
    ledStrip->setPixel(offset + localIndex, red, green, blue);
}

void Matrix::show() {
    if (ledStrip) ledStrip->show();
}
