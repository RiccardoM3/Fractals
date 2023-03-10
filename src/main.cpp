#include "helpers/vector2.hpp"
#include "fractal.hpp"
#include "fractal_quadratic.hpp"
#include "fractal_cubic.hpp"
#include "fractal_experiment.hpp"
#include "fractal_renderer.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

//TODO: needs to be moved into a class. also shouldnt need to pass references for first 2 params
void handleKeyPress(Fractal* fractal, FractalRenderer& renderer, sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::Up:
            fractal->SetConstant(fractal->GetConstant() + Vector2d(0.025, 0));
            break;
        case sf::Keyboard::Down:
            fractal->SetConstant(fractal->GetConstant() + Vector2d(-0.025, 0));
            break;
        case sf::Keyboard::Left:
            fractal->SetConstant(fractal->GetConstant() + Vector2d(0, 0.025));
            break;
        case sf::Keyboard::Right:
            fractal->SetConstant(fractal->GetConstant() + Vector2d(0, -0.025));
            break;

        case sf::Keyboard::W:
            renderer.TranslateBounds(0, 1);
            break;
        case sf::Keyboard::S:
            renderer.TranslateBounds(0, -1);
            break;
        case sf::Keyboard::A:
            renderer.TranslateBounds(-1, 0);
            break;
        case sf::Keyboard::D:
            renderer.TranslateBounds(1, 0);
            break;

        case sf::Keyboard::Q:
            renderer.ZoomOut();
            break;
        case sf::Keyboard::E:
            renderer.ZoomIn();
            break;

        case sf::Keyboard::R:
            fractal->SetMaxIterations(fractal->GetMaxIterations() + 50);
            break;
        case sf::Keyboard::T:
            fractal->SetMaxIterations(fractal->GetMaxIterations() - 50);
            break;
    }
}

int main() {
    Vector2i resolution = {1000, 1000};
    std::unique_ptr<Fractal> fractal = std::make_unique<ExperimentFractal>();
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
                    handleKeyPress(fractal.get(), renderer, event.key.code);
                    break;
            }
        }

        renderer.Render(fractal.get());

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
