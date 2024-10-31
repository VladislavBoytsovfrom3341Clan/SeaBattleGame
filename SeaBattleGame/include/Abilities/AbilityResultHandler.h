#ifndef ABILITY_RESULT_HANDLER_H
#define ABILITY_RESULT_HANDLER_H

#include "IAbilitySettings.h"

class AbilityResultHandler
{
    AbilityResult* mResult = nullptr;

public:
    template<typename R>
    void setResult(R* result)
    {
        mResult = static_cast<AbilityResult*>(result);
    }

    AbilityResult* getResult();
};

#endif