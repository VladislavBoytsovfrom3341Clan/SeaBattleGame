#include"Scanner.h"

#include<stdexcept>

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

ScannerResult::ScannerResult(int num):
mSegNum(num){}

int ScannerResult::getResult()
{
    return mSegNum;
}

Scanner::Scanner(Battlefield& field, Coords coords, AbilityResultHandler& handler):
mField(field), mCoords(coords), mHandler(handler){}

void Scanner::cast()
{
    int mSegNum = 0;
    for(int i=mCoords.y; i<mCoords.y+scannerRange; i++)
        for(int j=mCoords.x; j<mCoords.x+scannerRange; j++)
            if(mField.hasShipAtCell(Coords{j ,i}))
                mSegNum++;
    AbilityResult* result = new ScannerResult(mSegNum);
    mHandler.setResult(result);
}
