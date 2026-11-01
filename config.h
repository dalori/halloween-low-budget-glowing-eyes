#pragma once
#include <Arduino.h>

#define LEDS_PER_MATRIX 64
#define MATRIX_COUNT 8
#define LEDS_COUNT (LEDS_PER_MATRIX * MATRIX_COUNT)
#define LEDS_PIN 1

constexpr uint8_t MIN_BRIGHTNESS = 80;
constexpr uint8_t MAX_BRIGHTNESS = 100;
constexpr unsigned long MIN_PAUSE = 2000;
constexpr unsigned long MAX_PAUSE = 6000;

constexpr unsigned long MIN_GLOW = 2000;
constexpr unsigned long MAX_GLOW = 5000;
constexpr unsigned long GLOW_FADE_TIME = 750;

constexpr unsigned long KNIGHT_DURATION_MIN = 1500;
constexpr unsigned long KNIGHT_DURATION_MAX = 5000;
constexpr unsigned long KNIGHT_STEP_TIME = 100;

constexpr unsigned long STROBE_DURATION_MIN = 2000;
constexpr unsigned long STROBE_DURATION_MAX = 4000;
constexpr unsigned long STROBE_ON_TIME = 30;
constexpr unsigned long STROBE_OFF_TIME = 30;

constexpr uint8_t GLOW_WEIGHT = 90;
constexpr uint8_t KNIGHT_WEIGHT = 9;
constexpr uint8_t STROBE_WEIGHT = 1;
