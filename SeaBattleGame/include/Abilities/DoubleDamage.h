#ifndef DOUBLE_DAMAGE_H
#define DOUBLE_DAMAGE_H

#include "IAbility.h"

class DoubleDamage: public IAbility
{
    int& mMultiplier;
public:
    DoubleDamage(int& multiplier);  
    void cast() override;
};

#endif