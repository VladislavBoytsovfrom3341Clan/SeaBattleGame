#ifndef SCANER_H
#define SCANER_H

#include"IAbility.h"
#include"AbilityResultHandler.h"
#include"Battlefield.h"

constexpr int scannerRange = 2;

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