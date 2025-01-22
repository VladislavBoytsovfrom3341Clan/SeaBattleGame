#ifndef SCANNER_H
#define SCANNER_H

#include "IAbility.h"
#include "AbilityResultHandler.h"
#include "Battlefield.h"
#include "ScannerSettings.h"

constexpr int scannerRange = 2;

/*
* Checks pointed by coords field cells
* in the area for ships
* and writes number of found segments into
* result handler
*/
class Scanner: public IAbility
{
    //Field to be checked
    Battlefield& mField;

    //Left-up coords of area
    Coords mCoords;

    //Handler storages the result
    AbilityResultHandler& mHandler;

public:

    Scanner(ScannerSettings* scSettings);

    //Checks area in the field for ship segments
    void cast() override;
};

#endif