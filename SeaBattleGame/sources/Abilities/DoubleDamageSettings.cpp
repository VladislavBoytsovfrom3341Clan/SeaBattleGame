#include "DoubleDamageSettings.h"

DoubleDamageSettings::DoubleDamageSettings(int& multiplier):
mMultiplier(multiplier){}

AbilityType DoubleDamageSettings::getType()
{
    return AbilityType::DoubleDamage;
}

void DoubleDamageSettings::acceptVisitor(IVisitor& visitor)
{
    visitor.visit(this);
}