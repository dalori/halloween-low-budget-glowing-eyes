#include "WhiteStrobeEffect.h"
#include "config.h"

void WhiteStrobeEffect::start(unsigned long now) {
    startedAt = now;
    lastToggle = now;
    duration = random(STROBE_DURATION_MIN, STROBE_DURATION_MAX + 1);
    isOn = false;
    matrix.clear();
}

bool WhiteStrobeEffect::update(unsigned long now) {
    if (now - startedAt >= duration) return true;
    unsigned long interval = isOn ? STROBE_ON_TIME : STROBE_OFF_TIME;
    if (now - lastToggle < interval) return false;

    lastToggle = now;
    isOn = !isOn;
    if (isOn) matrix.fill(255, 255, 255);
    else matrix.clear();
    return false;
}
