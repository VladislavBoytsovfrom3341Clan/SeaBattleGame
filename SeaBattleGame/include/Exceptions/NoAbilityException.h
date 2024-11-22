#ifndef NO_ABILITY_EXCEPTION_H
#define NO_ABILITY_EXCEPTION_H

#include<string>

class NoAbilityException
{
    std::string mMessage;
public:
    NoAbilityException(std::string message = "");

    std::string what() const noexcept;
};

#endif