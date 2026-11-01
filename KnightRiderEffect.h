#pragma once
#include "Effect.h"

class KnightRiderEffect : public Effect {
public:
    using Effect::Effect;
    void start(unsigned long now) override;
    bool update(unsigned long now) override;
private:
    unsigned long startedAt = 0;
    unsigned long lastStep = 0;
    unsigned long duration = 0;
    int row = 0;
    int direction = 1;
    uint8_t brightness = 0;
    void render();
};
