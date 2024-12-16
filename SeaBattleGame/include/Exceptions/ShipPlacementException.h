#ifndef SHIP_PLACEMENT_EXCEPTION_H
#define SHIP_PLACEMENT_EXCEPTION_H

#include "Coords.h"

#include <string>

class ShipPlacementException
{
    Coords mShipCoords;
    std::string mMessage = "";
public:
    ShipPlacementException(Coords shipCoords, std::string message = "");

    std::string what() const noexcept;
};

#endif