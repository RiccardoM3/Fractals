#pragma once

#include "helpers/vector2.hpp"

class Fractal
{
public:
    int ComputeIterations(Vector2d z0);

private:
    Vector2d ComputeNext(Vector2d current);

    double escapeRadius = 2.0;
    Vector2d constant = {1.0, 1.0}; 
    int maxIterations = 50.0;
};