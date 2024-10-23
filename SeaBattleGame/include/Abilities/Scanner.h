#ifndef SCANER_H
#define SCANER_H

#include"IAbility.h"
#include"IAbilitySettings.h"
#include"Battlefield.h"

constexpr int scannerRange = 2;

class ScannerSettings: public IAbilitySettings
{
public:
    Battlefield& mField;
    Coords mCoords;

    ScannerSettings(Battlefield& field, Coords coords);
    AbilityType getType() override;
};

class Scanner: public IAbility
{
    class ResultScanner
    {
        int mSegNumber = 0;
    public:
        void setResult(int num) noexcept;
        void add() noexcept;
        int getSegNumber() const noexcept;
        bool containShips() const noexcept;
    };

    ResultScanner result;
    Battlefield& mField;
    Coords mCoords;
public:
    Scanner(Battlefield& field, Coords coords);
    void cast() override;
    bool containShips() const noexcept;
    int getSegNum() const noexcept;
};

#endif