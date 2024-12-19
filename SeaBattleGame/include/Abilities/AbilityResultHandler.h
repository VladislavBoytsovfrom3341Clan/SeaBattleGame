#ifndef ABILITY_RESULT_HANDLER_H
#define ABILITY_RESULT_HANDLER_H

#include "AbilityResult.h"

/*
* Class used for storaging and receiving result of casted abilities
*/
class AbilityResultHandler
{
    AbilityResult* mResult = nullptr;   //storages result

public:

    void setResult(AbilityResult* result) noexcept;

    AbilityResult* getResult() const noexcept;
};

#endif