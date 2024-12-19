#include "NoAbilityException.h"

NoAbilityException::NoAbilityException(std::string message):
mMessage(message){}

const char* NoAbilityException::what() const noexcept
{
    std::string output = "Trying to use ability,"
        "but no is available; thrown exception with message: "+mMessage;

    char* ret = new char[output.size() + 1];
    std::strcpy(ret, output.c_str());
    return ret;
}