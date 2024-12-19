#ifndef DOUBLE_DAMAGE_H
#define DOUBLE_DAMAGE_H

#include "IAbility.h"
#include "DoubleDamageSettings.h"

/*
* ability sets some given multiplier to 2
*/
class DoubleDamage: public IAbility
{
    int& mMultiplier;   //extern multiplier to be set

public:

    DoubleDamage(DoubleDamageSettings* ddSettings);  

    void cast() override;
};

#endif