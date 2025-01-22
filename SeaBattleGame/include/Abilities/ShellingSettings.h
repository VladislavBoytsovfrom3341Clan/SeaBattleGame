#ifndef SHELLING_SETTINGS_H
#define SHELLING_SETTINGS_H

#include "AbilityType.h"
#include "IAbilitySettings.h"
#include "ShipManager.h"

/*
* Struct decribing settings for shelling ability
* Holds enemy's ship manager
*/
struct ShellingSettings: public IAbilitySettings
{
public:

    //Enemy's ship manager
    ShipManager& mManager;


    ShellingSettings(ShipManager& manager);

    AbilityType getType() override;

    //Visitor deducts type of ability to build
    void acceptVisitor(IVisitor& visitor) override;
};

#endif