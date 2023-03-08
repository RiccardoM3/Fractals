#include "fractal.hpp"

int Fractal::ComputeIterations(Vector2d z0) {
    Vector2d zn = z0;
    int iteration = 0;
    while (zn.mod() < ESCAPE_RADIUS && iteration < mMaxIterations) {
        zn = ComputeNext(zn);
        iteration++;
    }
    return iteration;
}

int Fractal::GetMaxIterations() const {
    return mMaxIterations;
}

void Fractal::SetMaxIterations(int iterations) {
    mMaxIterations = iterations;
}

Vector2d Fractal::GetConstant() const {
    return mConstant;
}

void Fractal::SetConstant(Vector2d constant) {
    mConstant = constant;
}