#ifndef SHELLING_H
#define SHELLING_H

#include"IAbility.h"
#include"CastableOnShipManager.h"

class Shelling: public IAbility, public CastableOnShipManager
{
public:
    Shelling() = default;
    void cast() override;
};

#endif