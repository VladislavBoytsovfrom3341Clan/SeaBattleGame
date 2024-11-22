#ifndef SHELLING_H
#define SHELLING_H

#include "IAbility.h"
#include "ShipManager.h"
#include "ShellingSettings.h"

class Shelling: public IAbility
{
    ShipManager& mShipManager;
public:
    Shelling(ShellingSettings* shSettings);
    void cast() override;
};

#endif