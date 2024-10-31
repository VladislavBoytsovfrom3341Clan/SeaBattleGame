#include"Battlefield.h"
#include "OutOfRangeAttackException.h"
#include "ShipPlacementException.h"

#include<iostream>

//sets basic field size
Battlefield::Battlefield(const int horizontalSize, const int verticalSize):
mHorizontalSize(horizontalSize), mVerticalSize(verticalSize)
{
    if(horizontalSize<minimalFieldSize or verticalSize<minimalFieldSize or 
    horizontalSize>maximalFieldSize or verticalSize>maximalFieldSize)
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
Battlefield::Battlefield(Battlefield&& moved)
{
    mHorizontalSize=std::move(moved.mHorizontalSize);
    mVerticalSize=std::move(moved.mVerticalSize);
    mBattlefieldArray=std::move(moved.mBattlefieldArray);
}

void Battlefield::setShip(Battleship& ship, Coords coords, Orientation orientation)
{
    /**
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
    if(x<0 or x>=mHorizontalSize-xOffset or y<0 or y>mVerticalSize-yOffset)
        throw ShipPlacementException(coords, "Out of map size");
    
    //collision check
    for(int j=y-1; j<=y+yOffset+1; j++)
        if(j>=0 and j<mVerticalSize)
            for(int i=x-1; i<=x+xOffset+1; i++)
                if(i>=0 and i<mHorizontalSize)
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
        }
}

bool Battlefield::hasShipAtCell(Coords coords) const
{
    if(coords.x<0 or coords.x>=mHorizontalSize or coords.y<0 or coords.y>=mVerticalSize)
        throw std::invalid_argument("Invalid cell indexes");

    return mBattlefieldArray[coords.y][coords.x].hasShip();
}

Coords Battlefield::size() const noexcept
{
    return Coords{mHorizontalSize, mVerticalSize};
}

CellStatus Battlefield::getCellStatus(Coords coords) const
{
    if(coords.x<0 or coords.x>=mHorizontalSize or coords.y<0 or coords.y>=mVerticalSize)
        throw std::invalid_argument("Invalid cell indexes");
    
    return mBattlefieldArray[coords.y][coords.x].getStatus();
}

SegmentCondition Battlefield::getCellShipCondition(Coords coords) const
{
    if(coords.x<0 or coords.x>=mHorizontalSize or coords.y<0 or coords.y>=mVerticalSize)
        throw std::invalid_argument("Invalid cell indexes");
    
    //may throw an exception if there is no ship
    return mBattlefieldArray[coords.y][coords.x].getSegmentCondition();
}

bool Battlefield::attackCell(Coords coords, int damage)
{
    if(coords.x>=mHorizontalSize or coords.y>=mVerticalSize)
        throw OutOfRangeAttackException(coords, {mHorizontalSize, mVerticalSize});
    return mBattlefieldArray[coords.y][coords.x].attackCell(damage);
}

//DEBUG METHOD
void Battlefield::display()
{
    /**
     *  - stays for unknown,
     *  * stays for empty,
     *  0 stays for shipped,
     *  x stays for damaged,
     *  X stays for destroyed
    */
    std::cout<<"\n";
    for(int y=0; y<mVerticalSize; y++)
    {
        for(int x=0; x<mHorizontalSize; x++)
        {
            if (mBattlefieldArray[y][x].getStatus() == CellStatus::unknown)
                std::cout<<"-";
            else if(mBattlefieldArray[y][x].getStatus() == CellStatus::empty)
                std::cout<<"*";
            else if(mBattlefieldArray[y][x].getStatus() == CellStatus::shipped)
            {
                if(mBattlefieldArray[y][x].getSegmentCondition() == SegmentCondition::intact)
                    std::cout<<"0";
                else if(mBattlefieldArray[y][x].getSegmentCondition() == SegmentCondition::damaged)
                    std::cout<<"x";
                else
                    std::cout<<"X";
            }
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
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

Battlefield& Battlefield::operator=(Battlefield&& moved)
{
    if(&moved!=this)
    {
        mHorizontalSize=std::move(moved.mHorizontalSize);
        mVerticalSize=std::move(moved.mVerticalSize);
        mBattlefieldArray=std::move(moved.mBattlefieldArray);
    }
    return *this;
}