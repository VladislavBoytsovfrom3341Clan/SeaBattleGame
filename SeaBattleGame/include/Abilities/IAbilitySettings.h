#ifndef I_ABILITY_SETTINGS_H
#define I_ABILITY_SETTINGS_H

#include "IVisitor.h"

enum class AbilityType
{
    DoubleDamage=1,
    Scanner,
    Shelling
};

class IAbilitySettings
{
public:
    virtual AbilityType getType()=0;
    virtual void acceptVisitor(IVisitor& visitor)=0;
};

#endif