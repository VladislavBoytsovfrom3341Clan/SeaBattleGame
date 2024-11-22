#include "AbilityFactory.h"

#include "DoubleDamage.h"
#include "Shelling.h"
#include "Scanner.h"

IAbility* AbilityFactory::getAbility()
{
    return mBuildedAbility;
}
