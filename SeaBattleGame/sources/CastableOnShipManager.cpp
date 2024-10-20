#include"CastableOnShipManager.h"

void CastableOnShipManager::set(ShipManager& manager) noexcept
{
    mShipManager=&manager;
}