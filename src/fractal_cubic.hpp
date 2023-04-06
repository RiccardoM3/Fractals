#pragma once

#include "fractal.hpp"
#include "helpers/vector2.hpp"

class CubicFractal : public Fractal
{
public:
    CubicFractal() {
        mMaxIterations = 100;
        mConstant = {0.55, 0.175};
    }

private:
    Vector2d ComputeNext(Vector2d& current, Vector2d& constant) override {
        const double real = current.x * current.x * current.x - 3.0 * current.x * current.y * current.y;
        const double im = 3.0 * current.x * current.x * current.y - current.y * current.y * current.y;
        return Vector2d{real, im} + constant;
    }
};