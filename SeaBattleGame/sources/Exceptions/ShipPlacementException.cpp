#include "ShipPlacementException.h"

ShipPlacementException::ShipPlacementException(Coords shipCoords, std::string message):
mShipCoords(shipCoords), mMessage(message){}

const char* ShipPlacementException::what() const noexcept
{
    std::string output = "Error at ship placement occured: "
        " trying to put ship at " + mShipCoords.toString();
    if(mMessage != "")
        output+=" with message: " + mMessage;
    output+='\n';

    char* ret = new char[output.size() + 1];
    std::strcpy(ret, output.c_str());
    return ret;
}