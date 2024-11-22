#include "NoAbilityException.h"

NoAbilityException::NoAbilityException(std::string message):
mMessage(message){}

std::string NoAbilityException::what() const noexcept
{
    std::string output = "Trying to use ability,"
        "but no is available; thrown exception with message: "+mMessage;

    return output;
}