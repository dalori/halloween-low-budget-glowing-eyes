#include "config.h"
#include "LedStrip.h"
#include "MatrixController.h"

LedStrip ledStrip;
MatrixController matrices[MATRIX_COUNT];

void setup() {
    ledStrip.begin();
    randomSeed(esp_random());

    unsigned long now = millis();
    for (uint16_t i = 0; i < MATRIX_COUNT; i++) {
        matrices[i].begin(ledStrip, i, now + random(0, 1500));
    }
}

void loop() {
    unsigned long now = millis();
    for (uint16_t i = 0; i < MATRIX_COUNT; i++) {
        matrices[i].update(now);
    }
}
