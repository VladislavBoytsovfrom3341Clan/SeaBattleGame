#include"Scanner.h"

#include<stdexcept>

ScannerSettings::ScannerSettings(Battlefield& field, Coords coords):
mField(field), mCoords(coords){}

AbilityType ScannerSettings::getType()
{
    return AbilityType::Scanner;
}

void ScannerSettings::acceptVisitor(IVisitor& visitor)
{
    visitor.visit(this);
}

Scanner::Scanner(Battlefield& field, Coords coords):
mField(field), mCoords(coords){}

void Scanner::ResultScanner::setResult(int num) noexcept
{
    mSegNumber=num;
}

void Scanner::ResultScanner::add() noexcept
{
    mSegNumber++;
}

int Scanner::ResultScanner::getSegNumber() const noexcept
{
    return mSegNumber;
}

bool Scanner::ResultScanner::containShips() const noexcept
{
    return mSegNumber>0;
}

void Scanner::cast()
{
    for(int i=mCoords.y; i<mCoords.y+scannerRange; i++)
        for(int j=mCoords.x; j<mCoords.x+scannerRange; j++)
            if(mField.hasShipAtCell(Coords{j ,i}))
                result.add();
}

bool Scanner::containShips() const noexcept
{
    return result.containShips();
}

int Scanner::getSegNum() const noexcept
{
    return result.getSegNumber();
}