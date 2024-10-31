#ifndef SCANNER_SETTINGS_H
#define SCANNER_SETTINGS_H

#include "IAbilitySettings.h"
#include "Battlefield.h"
#include "AbilityResultHandler.h"

class ScannerSettings: public IAbilitySettings
{
public:
    Battlefield& mField;
    Coords mCoords;
    AbilityResultHandler& mHandler;

    ScannerSettings(Battlefield& field, Coords coords, AbilityResultHandler& handler);

    AbilityType getType() override;

    void acceptVisitor(IVisitor& visitor) override;
};

#endif