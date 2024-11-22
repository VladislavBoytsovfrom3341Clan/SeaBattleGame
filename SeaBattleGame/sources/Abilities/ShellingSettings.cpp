#include "ShellingSettings.h"

ShellingSettings::ShellingSettings(ShipManager& manager):
mManager(manager){}

AbilityType ShellingSettings::getType()
{
    return AbilityType::Shelling;
}

void ShellingSettings::acceptVisitor(IVisitor& visitor)
{
    visitor.visit(this);
}