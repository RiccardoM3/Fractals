#pragma once

#include "helpers/vector2.hpp"

class Fractal
{
public:
    const static int MAX_ITERATIONS = 75;
    
    int ComputeIterations(Vector2d z0);
    
    Vector2d GetConstant();
    void SetConstant(Vector2d constant);

private:
    Vector2d ComputeNext(Vector2d current);

    double mEscapeRadius = 2.0;
    Vector2d mConstant = {0.4, 0.2}; 
};