#ifndef SHELLING_H
#define SHELLING_H

#include"IAbility.h"
#include"ShipManager.h"

class Shelling: public IAbility
{
    ShipManager& mShipManager;
public:
    Shelling(ShipManager& manager);
    void cast() override;
};

#endif