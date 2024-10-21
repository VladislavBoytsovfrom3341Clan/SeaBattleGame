#ifndef DOUBLE_DAMAGE_H
#define DOUBLE_DAMAGE_H

#include"IAbility.h"
#include"CastableOnMap.h"

class DoubleDamage: public IAbility, public CastableOnMap
{
public:
    DoubleDamage() = default;
    void cast() override;
};

#endif