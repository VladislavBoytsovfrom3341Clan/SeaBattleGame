#ifndef ABILITY_RESULT_HANDLER_H
#define ABILITY_RESULT_HANDLER_H

#include "AbilityResult.h"

/*
* Class used for storaging and receiving result of casted abilities
* Basically just getter and setter with polymorphism
*/
class AbilityResultHandler
{
    //Storages result
    AbilityResult* mResult = nullptr;   

public:

    void setResult(AbilityResult* result) noexcept;

    AbilityResult* getResult() const noexcept;
};

#endif