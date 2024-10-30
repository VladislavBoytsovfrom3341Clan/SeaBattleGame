#include"DoubleDamage.h"

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

DoubleDamage::DoubleDamage(int& multiplier):
mMultiplier(multiplier){}

void DoubleDamage::cast()
{
    mMultiplier = 2;
}