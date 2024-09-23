#include"Battlefield.h"
#include<iostream>

const int minimalFieldSize = minimalShipLength;
const int maximalFieldSize = 25;

void Battlefield::BattlefieldCell::setShipSegment(Battleship* shipPointer, const int shipSegmentIndex)
{
    mShipPointer = shipPointer;
    mShipSegmentIndex = shipSegmentIndex;
}

void Battlefield::BattlefieldCell::attackCell(const int damage)
{
    if (mShipPointer == nullptr)
        mStatus = CellStatus::empty;
    else
    {
        mShipPointer->damageSegment(mShipSegmentIndex, damage);
        mStatus = CellStatus::shipped;
    }
}

Battlefield::Battlefield(const int horizontalSize, const int verticalSize):mHorizontalSize(horizontalSize), mVerticalSize(verticalSize)
{
    if(horizontalSize<minimalFieldSize or verticalSize<minimalFieldSize or horizontalSize>maximalFieldSize or verticalSize>maximalFieldSize)
        throw std::logic_error("Invalid field size");
    mBattlefieldArray.resize(mVerticalSize);
    for(int y=0;y<mVerticalSize; y++)
    {
        mBattlefieldArray[y].resize(mHorizontalSize);
        for(int x=0; x<mHorizontalSize; x++)
        {
            BattlefieldCell newCell;
            mBattlefieldArray[y].push_back(newCell);
        }
    }
}

CellStatus Battlefield::BattlefieldCell::getStatus()
{
    return mStatus;
}

SegmentCondition Battlefield::BattlefieldCell::getSegmentCondition()
{
    if (mShipPointer == nullptr)
        throw std::logic_error("No ship handles this cell");
    return mShipPointer->getSegmentCondition(mShipSegmentIndex);
}

bool Battlefield::BattlefieldCell::hasShip()
{
    if (mShipPointer == nullptr)
        return false;
    return true;
}

void Battlefield::setShip(Battleship* ship, int x, int y, Orientation orientation)
{
    int xOffset, yOffset;
    if(ship == nullptr)
        throw std::invalid_argument("Ship pointer is nullptr");
    if(orientation == Orientation::horizontal)
    {
        xOffset = ship->getLength()-1;
        yOffset = 0;
    }
    else
    {
        xOffset=0;
        yOffset=ship->getLength()-1;
    }
    if(x<0 or x>=mHorizontalSize-xOffset or y<0 or y>mVerticalSize-yOffset)
        throw std::invalid_argument("Invalid ship coordinates");
    for(int j=y-1; j<y+yOffset+1; j++)
        if(j>=0 and j<mVerticalSize)
            for(int i=x-1; i<x+xOffset; i++)
                if(i>=0 and i<mHorizontalSize)
                    if(mBattlefieldArray[j][i].hasShip())
                        throw std::logic_error("Intersection between ships occured");

    int segmentIndex=0;
    for(int j=y; j<=y+yOffset; j++)
        for(int i=x; i<=x+xOffset; i++)
            mBattlefieldArray[j][i].setShipSegment(ship, segmentIndex++);  
}

void Battlefield::attackCell(int x, int y)
{
    mBattlefieldArray[y][x].attackCell(1);
}

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