#include "AbilityFactory.h"

IAbility* AbilityFactory::getAbility()
{
    return mBuildedAbility;
}

void AbilityFactory::buildDoubleDamage(DoubleDamageSettings* ddSettings)
{
    mBuildedAbility = new DoubleDamage(ddSettings->mMultiplier);
}

void AbilityFactory::buildShelling(ShellingSettings* shSettings)
{
    mBuildedAbility = new Shelling(shSettings->mManager);
}

void AbilityFactory::buildScanner(ScannerSettings* scSettings)
{
    mBuildedAbility = new Scanner(scSettings->mField, scSettings->mCoords, scSettings->mHandler);
}