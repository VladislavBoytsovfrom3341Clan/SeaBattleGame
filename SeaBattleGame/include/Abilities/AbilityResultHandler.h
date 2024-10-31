#ifndef ABILITY_RESULT_HANDLER_H
#define ABILITY_RESULT_HANDLER_H

#include "IAbilitySettings.h"

class AbilityResultHandler
{
    AbilityResult* mResult = nullptr;

public:
    void setResult(AbilityResult* result);
    AbilityResult* getResult();
};

#endif