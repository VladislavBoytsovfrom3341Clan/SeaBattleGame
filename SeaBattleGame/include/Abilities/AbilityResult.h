#ifndef ABILITY_RESULT_H
#define ABILITY_RESULT_H

#include "AbilityType.h"

/*
* Interface describing results for some abilities
* Is virtual as sacrifice to polymorphism
*/
class AbilityResult
{
public:
    virtual AbilityType getType() const = 0;
};

#endif