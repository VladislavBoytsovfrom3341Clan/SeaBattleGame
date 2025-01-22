#ifndef SCANNER_SETTINGS_H
#define SCANNER_SETTINGS_H

#include "IAbilitySettings.h"
#include "Battlefield.h"
#include "AbilityResultHandler.h"

/*
* Settings for Scanner ability
* Has field to be scanned, 
* coords of left-up corner of area
* and handler for storaging the result
*/
struct ScannerSettings: public IAbilitySettings
{
public:
    //Field to be scanned
    Battlefield& mField;

    //Left-Up corner coords
    Coords mCoords;

    AbilityResultHandler& mHandler;


    ScannerSettings(Battlefield& field, Coords coords, AbilityResultHandler& handler);

    AbilityType getType() override;

    //Visitor deducts type of ability to build
    void acceptVisitor(IVisitor& visitor) override;
};

#endif