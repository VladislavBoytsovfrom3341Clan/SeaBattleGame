#include "AbilityFactory.h"


IAbility* AbilityFactory::getAbility() const noexcept
{
    return mBuildedAbility;
}
