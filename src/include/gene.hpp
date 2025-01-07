#pragma once
#include <array>

struct Gene
{
    int id;
    int cellType;
    int up,down,left,right;

};

struct Genome
{
    std::array<Gene*,32> genes;

};

