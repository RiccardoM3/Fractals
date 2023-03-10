#pragma once

#include "helpers/vector2.hpp"
#include "fractal.hpp"

#include <vector>

#include <SFML/Graphics.hpp>

class FractalRenderer 
{
public:
    FractalRenderer(Vector2i resolution);

    void TranslateBounds(double real, double im);
    void ZoomIn();
    void ZoomOut();
    void Render(Fractal* fractal);
    int IterationsToGradient(Fractal* fractal, int iterations) const;

    const sf::Texture& GetTexture() const;

private:
    Vector2i mResolution;
    sf::Texture mTexture;
    std::vector<sf::Uint8> mPixels;
    double mMaxReal;
    double mMinReal;
    double mMaxIm;
    double mMinIm;
    const int mTranslateSpeed;    // pixel multiplier when translating
};