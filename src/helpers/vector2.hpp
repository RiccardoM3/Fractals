#pragma once

#include <cmath>

template <typename T>
class Vector2
{
public:
    Vector2(T x, T y)
        : x(x)
        , y(y)
    {
    }

    T x;
    T y;

    T mod() const {
        return sqrt(x * x + y * y);
    }

    Vector2<T> operator+ (const Vector2<T>& first) const
    {
        return Vector2<T> (x + first.x, y + first.y);
    }
};

using Vector2i = Vector2<int>;
using Vector2d = Vector2<double>;