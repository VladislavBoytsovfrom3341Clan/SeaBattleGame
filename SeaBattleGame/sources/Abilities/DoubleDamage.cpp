#include"DoubleDamage.h"

DoubleDamage::DoubleDamage(int& multiplier):
mMultiplier(multiplier){}

void DoubleDamage::cast()
{
    mMultiplier = 2;
}