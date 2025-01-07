#pragma once
#include <SFML/Graphics.hpp>

struct Cell
{
    int cellType;
    int geneID = -1;
    Cell(int cellType = 0) : cellType(cellType), geneID(-1) {}
};

