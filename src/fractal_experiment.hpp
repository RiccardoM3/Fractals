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
        const double real = pow(current.x, 3) - 6.0*pow(current.x, 2)*pow(current.y, 2) + pow(current.y, 5);
        const double im = 4.0*pow(current.x, 3)*current.y - 4.0*current.x*pow(current.y, 3);
        return Vector2d{real, im} + mConstant;
    }
};