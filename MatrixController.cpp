#include "MatrixController.h"
#include "config.h"

MatrixController::MatrixController()
    : glow(matrix), knight(matrix), strobe(matrix), activeEffect(nullptr), nextEffectAt(0), waiting(true) {}

void MatrixController::begin(LedStrip& strip, uint16_t matrixIndex, unsigned long now) {
    matrix.begin(strip, matrixIndex);
    scheduleNext(now);
}

Effect* MatrixController::chooseEffect() {
    const uint8_t totalWeight = GLOW_WEIGHT + KNIGHT_WEIGHT + STROBE_WEIGHT;
    uint8_t choice = random(0, totalWeight);
    if (choice < GLOW_WEIGHT) return &glow;
    if (choice < GLOW_WEIGHT + KNIGHT_WEIGHT) return &knight;
    return &strobe;
}

void MatrixController::scheduleNext(unsigned long now) {
    activeEffect = nullptr;
    waiting = true;
    matrix.clear();
    nextEffectAt = now + random(MIN_PAUSE, MAX_PAUSE + 1);
}

void MatrixController::update(unsigned long now) {
    if (waiting) {
        if (now < nextEffectAt) return;
        activeEffect = chooseEffect();
        activeEffect->start(now);
        waiting = false;
        return;
    }

    if (activeEffect->update(now)) scheduleNext(now);
}
