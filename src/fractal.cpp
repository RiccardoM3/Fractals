#include "fractal.hpp"

int Fractal::ComputeIterations(Vector2d z0) {
    Vector2d z_n = {0, 0};
    Vector2d constant = mConstant;
    if (mType == Type::Julia) {
        z_n = z0;
    } else {
        constant = z0;
    }

    int iteration = 0;
    while (z_n.mod() < ESCAPE_RADIUS && iteration < mMaxIterations) {
        z_n = ComputeNext(z_n, constant);
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

void Fractal::SetType(Type type) {
    mType = type;
}