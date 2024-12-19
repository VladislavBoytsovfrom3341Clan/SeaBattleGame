#include "OutOfRangeAttackException.h"

#include <string>

OutOfRangeAttackException::OutOfRangeAttackException(Coords attackCoords, Coords fieldSize):
mFieldSize(fieldSize), mAttackCoords(attackCoords){}

const char* OutOfRangeAttackException::what() const noexcept
{
    std::string message = "Trying to attack ship at " +
        mAttackCoords.toString() +
        " , while field size is " +
        mFieldSize.toString() + '\n';

    char* ret = new char[message.size() + 1];
    std::strcpy(ret, message.c_str());
    return ret;
}