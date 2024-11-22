#include"DoubleDamage.h"

DoubleDamage::DoubleDamage(DoubleDamageSettings* ddSettings) :
    mMultiplier(ddSettings->mMultiplier) {}

void DoubleDamage::cast()
{
    mMultiplier = 2;
}