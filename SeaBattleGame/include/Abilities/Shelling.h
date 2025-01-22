#ifndef SHELLING_H
#define SHELLING_H

#include "IAbility.h"
#include "ShipManager.h"
#include "ShellingSettings.h"

/*
* Ability that damager random enemy ship
* Uses ShipManager of enemy to find target
*/
class Shelling: public IAbility
{
    //Enemy's ship manager
    ShipManager& mShipManager;
public:

    Shelling(ShellingSettings* shSettings);

    //Attacks random segment of random ship in given ship manager
    void cast() override;
};

#endif