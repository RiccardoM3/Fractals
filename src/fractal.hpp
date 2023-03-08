#pragma once

#include "helpers/vector2.hpp"

class Fractal
{
public:
    constexpr static double ESCAPE_RADIUS = 2.0;
    
    int ComputeIterations(Vector2d z0);

    int GetMaxIterations() const;
    void SetMaxIterations(int iterations);
    Vector2d GetConstant() const;
    void SetConstant(Vector2d constant);

protected:
    virtual Vector2d ComputeNext(Vector2d current) = 0;

    int mMaxIterations = 100;
    Vector2d mConstant = {0.1, 0.1}; 
};