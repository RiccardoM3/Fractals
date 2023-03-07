#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

int main() {
    std::cout << "hi" << std::endl;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
   
    sf::Texture texture;
    texture.create(200, 200);
    std::vector<sf::Uint8> pixels(200 * 200 * 4, 128); // 3 bytes per pixel (RGB)
    texture.update(pixels.data());

    // Create a sprite to display the texture
    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}

// void generate() {
    
//     for (int y = 0; y < resolution.y; y++) {
//         for (int x = 0; x < resolution.x; x++) {
//             //compute pixel's coordinates
//             const double px = x;
//             const double py = y;

//             const double iterations = computeIterations({px, py}, constant, 50);
//         }
//     }
// }

// int computeIterations(Vec2 z0, vec2 constant, int max_iteration) {
//     Vec2 zn = z0;
//     int iteration = 0;
//     while (mod2(zn) < escape_radius && iteration < max_iteration) {
//         zn = computeNext(zn, constant);
//         iteration++;
//     }
//     return iteration;
// }

// Vec2 computeNext(Vec2 current, Vec2 constant) {
//     const double real = current.x * current.x - current.y * current.y;
//     const double im = 2.0 * current.x * current.y;
//     return Vec2{real, im} + constant
// }