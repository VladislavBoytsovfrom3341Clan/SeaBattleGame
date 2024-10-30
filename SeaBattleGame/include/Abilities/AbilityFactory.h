#ifndef ABILITY_FACTORY_H
#define ABILITY_FACTORY_H

#include "IAbility.h"
#include "DoubleDamage.h"
#include "Shelling.h"
#include "Scanner.h"

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