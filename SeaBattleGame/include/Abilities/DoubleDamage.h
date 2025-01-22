#ifndef DOUBLE_DAMAGE_H
#define DOUBLE_DAMAGE_H

#include "IAbility.h"
#include "DoubleDamageSettings.h"

/*
* Used to change player attack stats
* for doubling next attack damage
* Ability sets some given multiplier to 2
*/
class DoubleDamage: public IAbility
{
    //Extern multiplier to be set
    int& mMultiplier;

public:

    DoubleDamage(DoubleDamageSettings* ddSettings);  

    //Doubles damage by setting multiplier to 2
    void cast() override;
};

#endif