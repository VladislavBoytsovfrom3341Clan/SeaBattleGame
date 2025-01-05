#ifndef NO_ABILITY_EXCEPTION_H
#define NO_ABILITY_EXCEPTION_H

#include <string>
#include <exception>

class NoAbilityException: public std::exception
{
    std::string mMessage;
public:
    NoAbilityException(std::string message = "");

    const char* what() const noexcept;
};

#endif