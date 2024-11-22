#ifndef ABILITY_RESULT_H
#define ABILITY_RESULT_H

#include "AbilityType.h"

class AbilityResult
{
public:
    virtual AbilityType getType() = 0;
};

#endif