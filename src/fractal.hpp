#pragma once

#include "helpers/vector2.hpp"

class Fractal
{
public:
    
    enum class Type {Julia, NonJulia};
    
    constexpr static double ESCAPE_RADIUS = 2.0;
    
    int ComputeIterations(Vector2d z0);

    int GetMaxIterations() const;
    void SetMaxIterations(int iterations);
    Vector2d GetConstant() const;
    void SetConstant(Vector2d constant);
    void SetType(Type type);

protected:
    virtual Vector2d ComputeNext(Vector2d& current, Vector2d& constant) = 0;

    Type mType = Type::Julia;
    int mMaxIterations = 100;
    Vector2d mConstant = {0.1, 0.1}; 
};