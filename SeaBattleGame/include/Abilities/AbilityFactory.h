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

    void buildDoubleDamage(DoubleDamageSettings* ddSettings);
    void buildShelling(ShellingSettings* shSettings);
    void buildScanner(ScannerSettings* scSettings);

    ~AbilityFactory() = default;
};

#endif