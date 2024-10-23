#ifndef SHELLING_H
#define SHELLING_H

#include"IAbility.h"
#include"IAbilitySettings.h"
#include"ShipManager.h"

class ShellingSettings: public IAbilitySettings
{
public:
    ShipManager& mManager;

    ShellingSettings(ShipManager& manager);
    AbilityType getType() override;
};

class Shelling: public IAbility
{
    ShipManager& mShipManager;
public:
    Shelling(ShipManager& manager);
    void cast() override;
};

#endif