#ifndef ABILITY_FACTORY_H
#define ABILITY_FACTORY_H

#include "IAbility.h"
#include "DoubleDamageSettings.h"
#include "ShellingSettings.h"
#include "ScannerSettings.h"

/*
* Class builds ability of type <AbilityType> with settings <SettingsType>,
* storages it and returns by any request
*/
class AbilityFactory
{
    //storages built ability
    IAbility* mBuildedAbility = nullptr;

public:
    AbilityFactory() = default;

    //Returns ability built using build()
    IAbility* getAbility() const noexcept;

    //Builds requested ability and storeges it
    template<typename SettingsType, typename AbilityType>
    void build(SettingsType* settings)
    {
        mBuildedAbility = new AbilityType(settings);
    }

    ~AbilityFactory() = default;
};

#endif