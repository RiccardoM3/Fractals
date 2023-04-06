#pragma once

#include "fractal.hpp"
#include "helpers/vector2.hpp"

#include <cmath>

class QuarticFractal : public Fractal
{
public:
    QuarticFractal() {
        mMaxIterations = 100;
        mConstant = {0.55, 0.175};
    }

private:
    Vector2d ComputeNext(Vector2d& current, Vector2d& constant) override {
        const double real = pow(current.x, 4) - 6.0*pow(current.x, 2)*pow(current.y, 2) + pow(current.y, 4);
        const double im = 4.0*pow(current.x, 3)*current.y - 4.0*current.x*pow(current.y, 3);
        return Vector2d{real, im} + constant;
    }
};