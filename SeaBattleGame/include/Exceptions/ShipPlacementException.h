#ifndef SHIP_PLACEMENT_EXCEPTION_H
#define SHIP_PLACEMENT_EXCEPTION_H

#include "Coords.h"

#include <exception>
#include <string>

class ShipPlacementException: public std::exception
{
    Coords mShipCoords;
    std::string mMessage = "";
public:
    ShipPlacementException(Coords shipCoords, std::string message = "");

    const char* what() const noexcept;
};

#endif