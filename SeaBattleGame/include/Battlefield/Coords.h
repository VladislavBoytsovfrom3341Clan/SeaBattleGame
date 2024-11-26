#ifndef COORDS_H
#define COORDS_H

#include <string>

//enum for ships orientation on the map
enum class Orientation
{
    horizontal,
    vertical
};

struct Coords
{
    int x;
    int y;

    Coords();

    Coords(int c_x, int c_y);

    std::string toString() const;
};

#endif