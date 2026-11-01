#include "GlowEffect.h"
#include "config.h"

void GlowEffect::start(unsigned long now) {
    startedAt = now;
    duration = random(MIN_GLOW, MAX_GLOW + 1);
    targetBrightness = random(MIN_BRIGHTNESS, MAX_BRIGHTNESS + 1);
}

bool GlowEffect::update(unsigned long now) {
    unsigned long elapsed = now - startedAt;
    if (elapsed >= duration) return true;

    uint8_t brightness = targetBrightness;
    if (elapsed < GLOW_FADE_TIME) {
        brightness = (uint32_t)targetBrightness * elapsed / GLOW_FADE_TIME;
    } else if (elapsed >= duration - GLOW_FADE_TIME) {
        brightness = (uint32_t)targetBrightness * (duration - elapsed) / GLOW_FADE_TIME;
    }

    matrix.fill(brightness, 0, 0);
    return false;
}
