#pragma once
#include "Effect.h"

class GlowEffect : public Effect {
public:
    using Effect::Effect;
    void start(unsigned long now) override;
    bool update(unsigned long now) override;
private:
    unsigned long startedAt = 0;
    unsigned long duration = 0;
    uint8_t targetBrightness = 0;
};
