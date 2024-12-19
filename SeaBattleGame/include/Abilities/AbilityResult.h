#ifndef ABILITY_RESULT_H
#define ABILITY_RESULT_H

#include "AbilityType.h"

/*
* Interface describing results for some abilities
*/
class AbilityResult
{
public:
    virtual AbilityType getType() = 0;
};

#endif