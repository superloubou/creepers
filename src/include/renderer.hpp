#pragma once
#include <SFML/Graphics.hpp>
#include <grid.hpp>

class Renderer
{
    static std::vector<sf::Color> colorMap;

  public:
    Renderer()
    {
        this->cellDrawShape.setSize(sf::Vector2f(8, 8));
        this->cellDrawShape.setFillColor(sf::Color(255, 0, 255));
        this->cellDrawShape.setOutlineColor(sf::Color::Black);
        this->cellDrawShape.setOutlineThickness(1);
    }

    void drawGrid(sf::RenderWindow &window, Grid &grid)
    {
        for (int r = 0; r < grid.numRows(); r++)
        {
            for (int c = 0; c < grid.numCols(); c++)
            {
                cellDrawShape.setPosition(sf::Vector2f(r * 8, c * 8));
                auto cell_value = grid.getAt(r, c).value;
                if (cell_value < 0 || cell_value > colorMap.size())
                {
                    this->cellDrawShape.setFillColor(sf::Color(255, 0, 255));
                }
                else
                {
                    this->cellDrawShape.setFillColor(colorMap[cell_value]);
                }
                window.draw(cellDrawShape);
            }
        }
    }

    sf::RectangleShape cellDrawShape;
};

std::vector<sf::Color> Renderer::colorMap = {
    sf::Color(179, 229, 252), // air
    sf::Color(128, 139, 150), // stone
    sf::Color(46, 125, 50),  // creeper
};