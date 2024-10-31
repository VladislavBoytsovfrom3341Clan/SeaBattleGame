#include "OutOfRangeAttackException.h"

#include <string>

OutOfRangeAttackException::OutOfRangeAttackException(Coords attackCoords, Coords fieldSize):
mFieldSize(fieldSize), mAttackCoords(attackCoords){}

std::string OutOfRangeAttackException::what() const noexcept
{
    std::string message = "Trying to attack ship at "+
        mAttackCoords.toString() + 
        " , while field size is " +
        mFieldSize.toString() + '\n';
    
    return message;
}