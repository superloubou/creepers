#pragma once

#include <cell.hpp>
#include <SFML/Graphics.hpp>
#include <gene.hpp>

class Grid
{
  private:
    int rows, cols;

    unsigned int index(int row, int col) const { return row * cols + col; }

    std::vector<Cell> data;

    bool isValidCell(int row, int col) const
    {
        if (row >= rows || col >= cols || col < 0 || row < 0)
        {
            return false;
        }
        return true;
    }

  public:
    Grid(int rows, int cols) : rows(rows), cols(cols) { data.resize(rows * cols); }

    Cell& getAt(int row, int col)
    {

        if (isValidCell(row, col))
        {
            return data.at(index(row, col));
        }
        throw std::out_of_range("Cell coordinates out of range.");
    }

    std::vector<Cell> getNeighbors(int row, int col)
    {
        std::vector<Cell> neighbors;

        const int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        for (const auto &dir : directions)
        {
            int neighborRow = row + dir[0];
            int neighborCol = col + dir[1];

            if (isValidCell(row, col))
            {
                Cell& neighbor = getAt(neighborRow, neighborCol);
                neighbors.push_back(neighbor);
            }
        }

        return neighbors;
    }

    auto getCardinalNeighbours(int row, int col) {}

    int numRows() const { return rows; }
    int numCols() const { return cols; }

    void grow(Genome genome)
    {
        std::vector<Cell> newdata(this->data);
        for (int r = 0; r < this->numRows(); r++)
        {
            for (int c = 0; c < this->numCols(); c++)
            {
                auto currentCell = this->getAt(r, c);
                auto currentGene = genome.genes[currentCell.geneID];
                auto upCell = this->getAt(r - 1, c);
                auto downCell = this->getAt(r + 1, c);
                auto leftCell = this->getAt(r, c - 1);
                auto rightCell = this->getAt(r, c + 1);
            }
        }
    }
};
