#include "Scanner.h"
#include "ScannerResult.h"

Scanner::Scanner(ScannerSettings* scSettings):
mField(scSettings->mField), mCoords(scSettings->mCoords), mHandler(scSettings->mHandler){}

//Simply double for() to search for ships
//Uses Battlefield::hasShipAtCell()
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
