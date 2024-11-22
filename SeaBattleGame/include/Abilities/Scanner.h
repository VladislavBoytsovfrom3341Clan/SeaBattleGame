#ifndef SCANER_H
#define SCANER_H

#include "IAbility.h"
#include "AbilityResultHandler.h"
#include "Battlefield.h"
#include "ScannerSettings.h"

constexpr int scannerRange = 2;

class Scanner: public IAbility
{
    Battlefield& mField;
    Coords mCoords;
    AbilityResultHandler& mHandler;
public:
    Scanner(ScannerSettings* scSettings);
    void cast() override;
};

#endif