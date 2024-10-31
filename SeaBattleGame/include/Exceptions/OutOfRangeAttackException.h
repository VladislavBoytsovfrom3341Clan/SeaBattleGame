#ifndef OUT_OF_RANGE_ATTACK_EXCEPTION_H
#define OUT_OF_RANGE_ATTACK_EXCEPTION_H

#include <stdexcept>
#include "Battlefield.h"
#include <string>

class OutOfRangeAttackException
{
    Coords mFieldSize;
    Coords mAttackCoords;
public:
    OutOfRangeAttackException(Coords attackCoords, Coords fieldSize);

    std::string what() const noexcept;
};

#endif