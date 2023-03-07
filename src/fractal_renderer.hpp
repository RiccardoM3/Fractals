#pragma once

#include "helpers/vector2.hpp"
#include "fractal.hpp"

#include <vector>

#include <SFML/Graphics.hpp>

class FractalRenderer 
{
public:
    FractalRenderer(Vector2i resolution);

    void SetBounds(double maxReal, double minReal, double maxIm, double minIm);
    void Render(Fractal& fractal);
    int IterationsToGradient(int iterations) const;

    const sf::Texture& GetTexture() const;

private:
    Vector2i mResolution;
    sf::Texture mTexture;
    std::vector<sf::Uint8> mPixels;
    double mMaxReal;
    double mMinReal;
    double mMaxIm;
    double mMinIm;

    int num;
};