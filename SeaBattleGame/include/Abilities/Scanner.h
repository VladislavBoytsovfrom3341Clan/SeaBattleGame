#ifndef SCANER_H
#define SCANER_H

#include"IAbility.h"
#include"IAbilitySettings.h"
#include"AbilityResultHandler.h"
#include"Battlefield.h"

constexpr int scannerRange = 2;

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

class ScannerResult: public AbilityResult
{
    int mSegNum = 0;
public:
    ScannerResult(int num);
    int getResult();
};

class Scanner: public IAbility
{
    Battlefield& mField;
    Coords mCoords;
    AbilityResultHandler& mHandler;
public:
    Scanner(Battlefield& field, Coords coords, AbilityResultHandler& handler);
    void cast() override;
};

#endif