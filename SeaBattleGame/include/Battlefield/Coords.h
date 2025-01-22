#ifndef COORDS_H
#define COORDS_H

#include <string>

//enum for ships orientation on the map
enum class Orientation
{
    horizontal,
    vertical
};

/*
* Used to set any point on Battlefield
*/
struct Coords
{
    int x;
    int y;

    Coords();

    Coords(int c_x, int c_y);

    //Converts to string for std::cout 'cause I'm lasy af
    std::string toString() const;
};

#endif