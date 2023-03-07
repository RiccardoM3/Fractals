#pragma once

#include "helpers/vector2.hpp"
#include "fractal.hpp"

#include <vector>

#include <SFML/Graphics.hpp>

class FractalRenderer 
{
public:
    FractalRenderer(Vector2i resolution);

    void SetBounds(Vector2d topLeft, Vector2d bottomRight);
    void Render(Fractal& fractal);

    const sf::Texture& GetTexture() const;

private:
    Vector2i mResolution;
    sf::Texture mTexture;
    std::vector<sf::Uint8> mPixels;

    int num;
};