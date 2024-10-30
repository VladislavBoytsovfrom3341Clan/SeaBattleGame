#include"DoubleDamage.h"

DoubleDamageSettings::DoubleDamageSettings(Battlefield& field, Coords coords):
mField(field), mCoords(coords){}

AbilityType DoubleDamageSettings::getType()
{
    return AbilityType::DoubleDamage;
}

void DoubleDamageSettings::acceptVisitor(IVisitor& visitor)
{
    visitor.visit(this);
}

DoubleDamage::DoubleDamage(Battlefield& field, Coords coords):
mField(field), mCoords(coords){}

void DoubleDamage::cast()
{
    mField.attackCell(mCoords, 2);
}