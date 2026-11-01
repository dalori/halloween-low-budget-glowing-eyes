#pragma once
#include "Matrix.h"
#include "GlowEffect.h"
#include "KnightRiderEffect.h"
#include "WhiteStrobeEffect.h"

class MatrixController {
public:
    MatrixController();
    void begin(LedStrip& strip, uint16_t matrixIndex, unsigned long now);
    void update(unsigned long now);
private:
    Matrix matrix;
    GlowEffect glow;
    KnightRiderEffect knight;
    WhiteStrobeEffect strobe;
    Effect* activeEffect;
    unsigned long nextEffectAt;
    bool waiting;
    Effect* chooseEffect();
    void scheduleNext(unsigned long now);
};
