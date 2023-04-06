#pragma once

#include "fractal.hpp"
#include "helpers/vector2.hpp"

class QuadraticFractal : public Fractal
{
public:
    QuadraticFractal() {
        mMaxIterations = 100;
        mConstant = {0.4, 0.2};
    }

private:
    Vector2d ComputeNext(Vector2d& current, Vector2d& constant) override {
        const double real = current.x * current.x - current.y * current.y;
        const double im = 2.0 * current.x * current.y;
        return Vector2d{real, im} + constant;
    }
};