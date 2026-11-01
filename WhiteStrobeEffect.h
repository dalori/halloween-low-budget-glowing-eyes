#pragma once
#include "Effect.h"

class WhiteStrobeEffect : public Effect {
public:
    using Effect::Effect;
    void start(unsigned long now) override;
    bool update(unsigned long now) override;
private:
    unsigned long startedAt = 0;
    unsigned long lastToggle = 0;
    unsigned long duration = 0;
    bool isOn = false;
};
