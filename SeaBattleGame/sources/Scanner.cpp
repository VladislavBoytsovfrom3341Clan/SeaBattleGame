#include"Scanner.h"

#include<stdexcept>

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

void Scanner::set(Battlefield& field, Coords coords)
{
    if(coords.x<0 or coords.x>=field.size().x-1 or coords.y<0 or coords.y>=field.size().y-1)
        throw std::invalid_argument("Invalid coords given");
    mField = &field;
    mCoords = coords;
}

void Scanner::cast()
{
    for(int i=mCoords.y; i<mCoords.y+scannerRange; i++)
        for(int j=mCoords.x; j<mCoords.x+scannerRange; j++)
            if(mField->hasShipAtCell(Coords{j ,i}))
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