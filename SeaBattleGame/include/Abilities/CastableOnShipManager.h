#ifndef CASTABLE_ON_SHIP_MANAGER_H
#define CASTABLE_ON_SHIP_MANAGER_H

#include "ShipManager.h"

class CastableOnShipManager
{
protected:
    ShipManager* mShipManager;
public:
    CastableOnShipManager() = default;
    void set(ShipManager& manager) noexcept;
};

#endif