#ifndef ABILITY_FACTORY_H
#define ABILITY_FACTORY_H

#include "IAbility.h"
#include "IAbilitySettings.h"

class AbilityFactory
{
public:
    IAbility* build(IAbilitySettings* settings);
};

#endif