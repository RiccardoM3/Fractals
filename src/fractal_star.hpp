#pragma once

#include "fractal.hpp"
#include "helpers/vector2.hpp"

#include <cmath>

class StarFractal : public Fractal
{
public:
    StarFractal() {
        mMaxIterations = 100;
        mConstant = {0.55, 0.175};
    }

private:
    Vector2d ComputeNext(Vector2d current) override {
        const double real = 2.0*pow(current.x, 3)*pow(current.y, 9);
        const double im = 4.0*pow(current.x, 3)*current.y - 4.0*current.x*pow(current.y, 3);
        return Vector2d{real, im} + mConstant;
    }
};