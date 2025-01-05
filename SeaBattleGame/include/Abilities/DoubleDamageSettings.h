#ifndef DOUBLE_DAMAGE_SETTINGS_H
#define DOUBLE_DAMAGE_SETTINGS_H

#include "AbilityType.h"
#include "IVisitor.h"
#include "IAbilitySettings.h"

/*
* Struct describing settings for double damage (multiplier)
*/
struct DoubleDamageSettings: public IAbilitySettings
{
public:
    int& mMultiplier;


    DoubleDamageSettings(int& multiplier);

    AbilityType getType() override;

    void acceptVisitor(IVisitor& visitor) override;
};

#endif