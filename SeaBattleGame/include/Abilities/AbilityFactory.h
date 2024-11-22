#ifndef ABILITY_FACTORY_H
#define ABILITY_FACTORY_H

#include "IAbility.h"
#include "DoubleDamageSettings.h"
#include "ShellingSettings.h"
#include "ScannerSettings.h"

class AbilityFactory
{
    IAbility* mBuildedAbility = nullptr;
public:
    AbilityFactory() = default;

    IAbility* getAbility();

    template<typename SettingsType, typename AbilityType>
    void build(SettingsType* settings)
    {
        mBuildedAbility = new AbilityType(settings);
    }

    ~AbilityFactory() = default;
};

#endif