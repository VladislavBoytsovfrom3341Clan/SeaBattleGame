#include "Coords.h"

#include <string>

Coords::Coords() :
    x(0), y(0) {}

Coords::Coords(int c_x, int c_y) :
    x(c_x), y(c_y) {}

std::string Coords::toString() const
{
    return '(' + std::to_string(x) + " , " + std::to_string(y) + ')';
}