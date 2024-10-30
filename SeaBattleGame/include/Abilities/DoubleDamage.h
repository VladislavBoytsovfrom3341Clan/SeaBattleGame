#ifndef DOUBLE_DAMAGE_H
#define DOUBLE_DAMAGE_H

#include "IAbility.h"
#include "IAbilitySettings.h"
#include "Battlefield.h"

class DoubleDamageSettings: public IAbilitySettings
{
public:
    int& mMultiplier;

    DoubleDamageSettings(int& multiplier);

    AbilityType getType() override;
    void acceptVisitor(IVisitor& visitor) override;
};

class DoubleDamage: public IAbility
{
    int& mMultiplier;
public:
    DoubleDamage(int& multiplier);  
    void cast() override;
};

#endif