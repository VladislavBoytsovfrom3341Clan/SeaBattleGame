#ifndef DOUBLE_DAMAGE_H
#define DOUBLE_DAMAGE_H

#include "IAbility.h"
#include "DoubleDamageSettings.h"

class DoubleDamage: public IAbility
{
    int& mMultiplier;
public:
    DoubleDamage(DoubleDamageSettings* ddSettings);  
    void cast() override;
};

#endif