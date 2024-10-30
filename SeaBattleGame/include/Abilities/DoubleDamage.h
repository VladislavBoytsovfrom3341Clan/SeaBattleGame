#ifndef DOUBLE_DAMAGE_H
#define DOUBLE_DAMAGE_H

#include "IAbility.h"
#include "IAbilitySettings.h"
#include "Battlefield.h"

class DoubleDamageSettings: public IAbilitySettings
{
public:
    Battlefield& mField;
    Coords mCoords;

    DoubleDamageSettings(Battlefield& field, Coords coords);

    AbilityType getType() override;
    void acceptVisitor(IVisitor& visitor) override;
};

class DoubleDamage: public IAbility
{
    Battlefield& mField;
    Coords mCoords;
public:
    DoubleDamage(Battlefield& field, Coords coords);  
    void cast() override;
};

#endif