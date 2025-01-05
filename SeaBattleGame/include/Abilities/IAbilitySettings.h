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

    virtual void acceptVisitor(IVisitor& visitor)=0;
};

#endif