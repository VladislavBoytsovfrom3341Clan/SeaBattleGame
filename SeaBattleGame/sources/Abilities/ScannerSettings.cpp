#include "ScannerSettings.h"

ScannerSettings::ScannerSettings(Battlefield& field, Coords coords, AbilityResultHandler& handler):
mField(field), mCoords(coords), mHandler(handler){}

AbilityType ScannerSettings::getType()
{
    return AbilityType::Scanner;
}

void ScannerSettings::acceptVisitor(IVisitor& visitor)
{
    visitor.visit(this);
}