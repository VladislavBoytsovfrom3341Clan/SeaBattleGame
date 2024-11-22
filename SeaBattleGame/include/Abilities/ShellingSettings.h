#ifndef SHELLING_SETTINGS_H
#define SHELLING_SETTINGS_H

#include "AbilityType.h"
#include "IAbilitySettings.h"
#include "ShipManager.h"

class ShellingSettings: public IAbilitySettings
{
public:
    ShipManager& mManager;

    ShellingSettings(ShipManager& manager);

    AbilityType getType() override;

    void acceptVisitor(IVisitor& visitor) override;
};

#endif