#include "KnightRiderEffect.h"
#include "config.h"

void KnightRiderEffect::start(unsigned long now) {
    startedAt = now;
    lastStep = now;
    duration = random(KNIGHT_DURATION_MIN, KNIGHT_DURATION_MAX + 1);
    row = 0;
    direction = 1;
    brightness = random(MIN_BRIGHTNESS, MAX_BRIGHTNESS + 1);
    render();
}

bool KnightRiderEffect::update(unsigned long now) {
    if (now - startedAt >= duration) return true;
    if (now - lastStep < KNIGHT_STEP_TIME) return false;

    lastStep = now;
    row += direction;
    if (row >= 6) {
        row = 6;
        direction = -1;
    } else if (row <= 0) {
        row = 0;
        direction = 1;
    }
    render();
    return false;
}

void KnightRiderEffect::render() {
    for (uint16_t i = 0; i < LEDS_PER_MATRIX; i++) matrix.setPixel(i, 0, 0, 0);
    for (int r = row; r <= row + 1; r++) {
        for (int col = 0; col < 8; col++) matrix.setPixel(r * 8 + col, brightness, 0, 0);
    }
    matrix.show();
}
