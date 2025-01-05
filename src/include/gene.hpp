#pragma once
#include <array>
#include <cstdint>

struct Gene
{
    uint8_t id;
    uint8_t up,down,left,right;

};

struct Genome
{
    std::array<Gene*,32> genes;

};

