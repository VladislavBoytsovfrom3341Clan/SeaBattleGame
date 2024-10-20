#include"Scanner.h"

void Scanner::ResultScanner::setResult(int num)
{
    mSegNumber=num;
}

void Scanner::ResultScanner::add()
{
    mSegNumber++;
}

int Scanner::ResultScanner::getSegNumber()
{
    return mSegNumber;
}

bool Scanner::ResultScanner::containShips()
{
    return mSegNumber>0;
}

void Scanner::cast()
{
    for(int i=mCoords.y; i<mCoords.y+scannerRange; i++)
        for(int j=mCoords.x; j<mCoords.x+scannerRange; j++)
            if(mField->hasShipAtCell(Coords{j ,i}))
                result.add();
}

bool Scanner::containShips()
{
    return result.containShips();
}

int Scanner::getSegNum()
{
    return result.getSegNumber();
}