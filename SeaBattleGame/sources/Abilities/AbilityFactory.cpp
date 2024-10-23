#include "AbilityFactory.h"

#include "IAbility.h"
#include "IAbilitySettings.h"
#include "DoubleDamage.h"
#include "Shelling.h"
#include "Scanner.h"

IAbility* AbilityFactory::build(IAbilitySettings* settings)
{
    switch (settings->getType())
    {
    case AbilityType::DoubleDamage:
    {
        DoubleDamageSettings ddSettings = dynamic_cast<DoubleDamageSettings&>(*settings);
        return new DoubleDamage(ddSettings.mField, ddSettings.mCoords);
        break;
    }
    case AbilityType::Scanner:
    {
        ScannerSettings scSettings = dynamic_cast<ScannerSettings&>(*settings);
        return new Scanner(scSettings.mField, scSettings.mCoords);
        break;
    }
    case AbilityType::Shelling:
    {
        ShellingSettings shSettings = dynamic_cast<ShellingSettings&>(*settings);
        return new Shelling(shSettings.mManager);
        break;
    }
    default:
        break;
    }
}