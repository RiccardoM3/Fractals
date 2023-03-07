#pragma once

#include "helpers/vector2.hpp"

class Fractal
{
public:
    int ComputeIterations(Vector2d z0);
    const static int MAX_ITERATIONS = 75;

private:
    Vector2d ComputeNext(Vector2d current);

    double escapeRadius = 2.0;
    Vector2d constant = {0.4, 0.2}; 
};