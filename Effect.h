#pragma once
#include <Arduino.h>
#include "Matrix.h"

class Effect {
public:
    explicit Effect(Matrix& matrix) : matrix(matrix) {}
    virtual ~Effect() = default;
    virtual void start(unsigned long now) = 0;
    virtual bool update(unsigned long now) = 0;
protected:
    Matrix& matrix;
};
