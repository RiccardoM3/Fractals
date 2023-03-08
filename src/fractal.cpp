#include "fractal.hpp"

int Fractal::ComputeIterations(Vector2d z0) {
    Vector2d zn = z0;
    int iteration = 0;
    while (zn.mod() < mEscapeRadius && iteration < MAX_ITERATIONS) {
        zn = ComputeNext(zn);
        iteration++;
    }
    return iteration;
}

Vector2d Fractal::ComputeNext(Vector2d current) {
    const double real = current.x * current.x - current.y * current.y;
    const double im = 2.0 * current.x * current.y;
    return Vector2d{real, im} + mConstant;
}

Vector2d Fractal::GetConstant() {
    return mConstant;
}

void Fractal::SetConstant(Vector2d constant) {
    mConstant = constant;
}