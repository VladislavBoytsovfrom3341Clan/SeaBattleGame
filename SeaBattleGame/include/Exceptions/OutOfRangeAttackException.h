#ifndef OUT_OF_RANGE_ATTACK_EXCEPTION_H
#define OUT_OF_RANGE_ATTACK_EXCEPTION_H

#include <exception>
#include "Coords.h"

class OutOfRangeAttackException: public std::exception
{
    Coords mFieldSize;
    Coords mAttackCoords;
public:
    OutOfRangeAttackException(Coords attackCoords, Coords fieldSize);

    const char* what() const noexcept;
};

#endif