#include"Battlefield.h"
#include "OutOfRangeAttackException.h"
#include "ShipPlacementException.h"

#include<iostream>

//sets basic field size
Battlefield::Battlefield(const int horizontalSize, const int verticalSize):
mHorizontalSize(horizontalSize), mVerticalSize(verticalSize)
{
    if(horizontalSize<minimalFieldSize || verticalSize<minimalFieldSize || 
    horizontalSize>maximalFieldSize || verticalSize>maximalFieldSize)
        throw std::logic_error("Invalid field size");

    //fulls field with empty cells
    mBattlefieldArray.resize(mVerticalSize);
    for(int y=0;y<mVerticalSize; y++)
    {
        mBattlefieldArray[y].resize(mHorizontalSize);
        for(int x=0; x<mHorizontalSize; x++)
        {
            mBattlefieldArray[y][x] = BattlefieldCell();
        }
    }
}

Battlefield::Battlefield(std::vector<std::vector<CellStatus>> init)
{
    mVerticalSize = init.size();
    mHorizontalSize = init[0].size();
    for (int y = 0; y < mVerticalSize; y++)
        for (int x = 0; x < mHorizontalSize; x++)
            mBattlefieldArray[y][x].setStatus(init[y][x]);
}

//ship poiners are copied, not ships
Battlefield::Battlefield(const Battlefield& copy):
Battlefield(copy.mHorizontalSize, copy.mVerticalSize)
{
    mBattlefieldArray.resize(mVerticalSize);
    for(int y=0;y<mVerticalSize; y++)
    {
        mBattlefieldArray[y].resize(mHorizontalSize);
        for(int x=0; x<mHorizontalSize; x++)
        {
            mBattlefieldArray[y][x] = copy.mBattlefieldArray[y][x];
        }
    }
}

//moves all stuff
Battlefield::Battlefield(Battlefield&& moved) noexcept
{
    mHorizontalSize=std::move(moved.mHorizontalSize);
    mVerticalSize=std::move(moved.mVerticalSize);
    mBattlefieldArray=std::move(moved.mBattlefieldArray);
}

void Battlefield::setShip(Battleship& ship, Coords coords, Orientation orientation)
{
    /*
     * Uses offset to calculate the exact ships area as
     * (x+xOffset, y+yOffset)
    */
    int xOffset, yOffset;
    if(orientation == Orientation::horizontal)
    {
        xOffset = ship.getLength()-1;
        yOffset = 0;
    }
    else
    {
        xOffset=0;
        yOffset=ship.getLength()-1;
    }

    int x=coords.x;
    int y=coords.y;

    //check if ship fits in the field
    if(x<0 || x>=mHorizontalSize-xOffset || y<0 || y>mVerticalSize-yOffset)
        throw ShipPlacementException(coords, "Out of map size");
    
    //collision check
    for(int j=y-1; j<=y+yOffset+1; j++)
        if(j>=0 && j<mVerticalSize)
            for(int i=x-1; i<=x+xOffset+1; i++)
                if(i>=0 && i<mHorizontalSize)
                {
                    if(mBattlefieldArray[j][i].hasShip())
                        throw ShipPlacementException(coords, "Intersection between ships occured");
                }
    //sets ship to the cells by segments
    int segmentIndex=0;
    for(int j=y; j<=y+yOffset; j++)
        for(int i=x; i<=x+xOffset; i++)
        {
            mBattlefieldArray[j][i].setShipSegment(ship, segmentIndex++);
            ship.setPosition(coords, orientation);
        }
}

bool Battlefield::hasShipAtCell(Coords coords) const
{
    if(coords.x<0 || coords.x>=mHorizontalSize || coords.y<0 || coords.y>=mVerticalSize)
        throw std::invalid_argument("Invalid cell indexes");

    return mBattlefieldArray[coords.y][coords.x].hasShip();
}

Battleship& Battlefield::getShip(Coords coords)
{
    return mBattlefieldArray[coords.y][coords.x].getShip();
}

Coords Battlefield::size() const noexcept
{
    return Coords{mHorizontalSize, mVerticalSize};
}

CellStatus Battlefield::getCellStatus(Coords coords) const
{
    if(coords.x<0 || coords.x>=mHorizontalSize || coords.y<0 || coords.y>=mVerticalSize)
        throw std::invalid_argument("Invalid cell indexes");
    
    return mBattlefieldArray[coords.y][coords.x].getStatus();
}

//may throw an exception if there is no ship
SegmentCondition Battlefield::getCellShipCondition(Coords coords) const
{
    if(coords.x<0 || coords.x>=mHorizontalSize || coords.y<0 || coords.y>=mVerticalSize)
        throw std::invalid_argument("Invalid cell indexes");
    
    //may throw an exception if there is no ship
    return mBattlefieldArray[coords.y][coords.x].getSegmentCondition();
}

bool Battlefield::attackCell(Coords coords, int damage)
{
    if(coords.x>=mHorizontalSize || coords.y>=mVerticalSize)
        throw OutOfRangeAttackException(coords, {mHorizontalSize, mVerticalSize});
    return mBattlefieldArray[coords.y][coords.x].attackCell(damage);
}

//ship poiners are copied, not ships
Battlefield& Battlefield::operator=(const Battlefield& copy)
{
    if(&copy!=this)
    {
        mHorizontalSize=copy.mHorizontalSize;
        mVerticalSize=copy.mVerticalSize;
        mBattlefieldArray.clear();
        mBattlefieldArray.resize(copy.mVerticalSize);
        for(int y=0;y<copy.mVerticalSize; y++)
        {
            mBattlefieldArray[y].resize(copy.mHorizontalSize);
            for(int x=0; x<copy.mHorizontalSize; x++)
            {
                mBattlefieldArray[y][x]= copy.mBattlefieldArray[y][x];
            }
        }
    }
    return *this;
}

Battlefield& Battlefield::operator=(Battlefield&& moved) noexcept
{
    if(&moved!=this)
    {
        mHorizontalSize=std::move(moved.mHorizontalSize);
        mVerticalSize=std::move(moved.mVerticalSize);
        mBattlefieldArray=std::move(moved.mBattlefieldArray);
    }
    return *this;
}

long long Battlefield::calculateControlSum()
{
    long long sum = 0;
    for(int y=0; y<mVerticalSize; y++)
        for (int x = 0; x < mHorizontalSize; x++)
        {
            switch (mBattlefieldArray[y][x].getStatus())
            {
            case CellStatus::unknown:
                sum += 17 * y * x;
                break;
            case CellStatus::empty:
                sum += 19 * y * x;
                break;
            case CellStatus::shipped:
                sum += 23 * y * x;
                break;
            default:
                break;
            }
        }
    return sum;
}

std::istream& operator>>(std::istream& is, Battlefield& field)
{
    long long readSum = 0;
    is >> readSum;
    is >> field.mHorizontalSize >> field.mVerticalSize;
    field.mBattlefieldArray.resize(field.mVerticalSize);
    for (int y = 0; y < field.mVerticalSize; y++)
    {
        field.mBattlefieldArray[y].resize(field.mHorizontalSize);
        for (int x = 0; x < field.mHorizontalSize; x++)
        {
            char buf;
            is >> buf;
            if (buf == '-')
                field.mBattlefieldArray[y][x].setStatus(CellStatus::unknown);
            else if(buf == '*')
                field.mBattlefieldArray[y][x].setStatus(CellStatus::empty);
            else
                field.mBattlefieldArray[y][x].setStatus(CellStatus::shipped);
        }
    }
    if (readSum != field.calculateControlSum())
        throw std::runtime_error("File reading error: invalid battlefield control sum\n");
    return is;
}

std::ostream& operator<<(std::ostream& os, Battlefield& field)
{
    os << field.calculateControlSum() << '\n';
    os << field.mHorizontalSize << ' ' << field.mVerticalSize << '\n';
    for (int y = 0; y < field.mVerticalSize; y++)
    {
        for (int x = 0; x < field.mHorizontalSize; x++)
        {
            if (field.mBattlefieldArray[y][x].getStatus() == CellStatus::unknown)
                os << "-";
            else if (field.mBattlefieldArray[y][x].getStatus() == CellStatus::empty)
                os << "*";
            else
                os << "0";
        }
        os << "\n";
    }
    return os;
}