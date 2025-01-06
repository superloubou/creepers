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
    grid.getAt(64, 64).cellType = 1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        renderer.drawGrid(window, grid);

        window.display();
    }

    return 0;
}

int calculateScore(Grid &grid)
{
    int score = 0;
    for (int r = 0; r < grid.numRows(); r++)
    {
        for (int c = 0; c < grid.numCols(); c++)
        {
            auto currentCell = grid.getAt(r, c);
            auto neighbours = grid.getNeighbors(r, c);
            int stemNeighbours = 0,petalNeighbours = 0;
            for (auto cell: neighbours)
            {
                if (cell.cellType == 1) stemNeighbours += 1;
                if (cell.cellType == 2) petalNeighbours += 1;
            }

            if (currentCell.cellType == 1)
            {
                score -= 1;
            }

            if (currentCell.cellType == 2)
            {
                score += 6;
                score -= stemNeighbours * 2;
            }
        }
    }
    return score;
}