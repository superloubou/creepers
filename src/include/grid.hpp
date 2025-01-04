#pragma once

#include <cell.hpp>
#include <stdexcept>
#include <SFML/Graphics.hpp>


class Grid
{
  private:
    size_t rows, cols;

    size_t index(size_t row, size_t col) const
    {
        if (row >= rows || col >= rows)
        {
            throw std::out_of_range("Grid index out of bounds");
        }
        return row * cols + col;
    }

    std::vector<Cell> data;

  public:
    Grid(size_t rows, size_t cols) : rows(rows), cols(cols) {
        data.resize(rows * cols);
    }

    Cell &at(size_t row, size_t col) { return data.at(index(row, col)); }

    size_t numRows() const { return rows; }
    size_t numCols() const { return cols; }

};
