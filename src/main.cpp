#include "helpers/vector2.hpp"
#include "fractal.hpp"
#include "fractal_renderer.hpp"

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

//TODO: needs to be moved into a class. also shouldnt need to pass references for first 2 params
void handleKeyPress(Fractal& fractal, FractalRenderer& renderer, sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::W:
            fractal.SetConstant(fractal.GetConstant() + Vector2d(0.025, 0));
            break;
        case sf::Keyboard::S:
            fractal.SetConstant(fractal.GetConstant() + Vector2d(-0.025, 0));
            break;
        case sf::Keyboard::A:
            fractal.SetConstant(fractal.GetConstant() + Vector2d(0, 0.025));
            break;
        case sf::Keyboard::D:
            fractal.SetConstant(fractal.GetConstant() + Vector2d(0, -0.025));
            break;
    }
}

int main() {
    Vector2i resolution = {1000, 1000};
    Fractal fractal;
    FractalRenderer renderer(resolution);
    sf::Sprite sprite(renderer.GetTexture());

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Fractal");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    handleKeyPress(fractal, renderer, event.key.code);
                    break;
            }

        }

        renderer.Render(fractal);

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
