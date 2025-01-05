#pragma once

#include <cell.hpp>
#include <SFML/Graphics.hpp>

class Grid
{
  private:
    size_t rows, cols;

    int index(size_t row, size_t col) const
    {
        if (row >= rows || col >= rows)
        {
            return -1;
        }
        return row * cols + col;
    }

    std::vector<Cell> data;
    Cell invalidCell;

  public:
    Grid(size_t rows, size_t cols) : rows(rows), cols(cols), invalidCell(-1) { data.resize(rows * cols); }

    Cell &getAt(size_t row, size_t col)
    {
        auto indexToGet = index(row, col);
        if (indexToGet < 0)
        {
            return invalidCell;
        }
        else
        {
            return data.at(indexToGet);
        }
    }

    std::vector<Cell> getNeighbors(size_t row, size_t col)
    {
        std::vector<Cell> neighbors;

        const int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        for (const auto &dir : directions)
        {
            size_t neighborRow = row + dir[0];
            size_t neighborCol = col + dir[1];

            if (neighborRow < rows && neighborCol < cols && neighborCol >= 0 && neighborRow >= 0)
            {
                neighbors.push_back(getAt(neighborRow, neighborCol));
            }
        }

        return neighbors;
    }

    size_t numRows() const { return rows; }
    size_t numCols() const { return cols; }
};
