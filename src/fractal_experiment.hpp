#pragma once

#include "fractal.hpp"
#include "helpers/vector2.hpp"

class ExperimentFractal : public Fractal
{
public:
    ExperimentFractal() {
        mMaxIterations = 100;
        mConstant = {1, 0};
    }

private:
    Vector2d ComputeNext(Vector2d current) override {
        const double real = 1.5 * (current.y * current.y - current.x * current.x) - 0.5 * current.x;
        const double im = -3 * current.x * current.y - 0.5 * current.y;
        return Vector2d{real, im} + mConstant;
    }
};