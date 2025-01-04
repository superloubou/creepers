#include <SFML/Graphics.hpp>
#include <grid.hpp>
#include <renderer.hpp>

const int SCREEN_HEIGHT = 1920, SCREEN_WIDTH = 1080;

constexpr size_t rows = 128, cols = 128;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_HEIGHT, SCREEN_WIDTH), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    Renderer renderer;

    Grid grid(rows, cols);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        renderer.drawGrid(window,grid);

        window.display();
    }

    return 0;
}