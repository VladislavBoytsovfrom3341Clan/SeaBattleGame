#ifndef I_ABILITY_SETTINGS_H
#define I_ABILITY_SETTINGS_H

#include "IVisitor.h"
#include "AbilityType.h"

/*
* Interface describing Ability settings behavior
*/
struct IAbilitySettings
{
public:

    virtual AbilityType getType()=0;

    //Virtual method to accept visitor in order to
    //deduct proper ability type to build
    virtual void acceptVisitor(IVisitor& visitor)=0;
};

#endif