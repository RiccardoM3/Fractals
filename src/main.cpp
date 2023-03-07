#include "helpers/vector2.hpp"
#include "fractal.hpp"
#include "fractal_renderer.hpp"

#include <vector>
#include <SFML/Graphics.hpp>

int main() {
    Vector2i resolution = {800, 600};
    Fractal fractal;
    FractalRenderer renderer(resolution);
    sf::Sprite sprite(renderer.GetTexture());

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Fractal");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        renderer.Render(fractal);

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
