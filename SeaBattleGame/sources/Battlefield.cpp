#include"Battlefield.h"
#include<iostream>

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
            mBattlefieldArray[y].emplace_back();
        }
    }
}

Battlefield::Battlefield(const Battlefield& copy):Battlefield(copy.mHorizontalSize, copy.mVerticalSize){}

Battlefield::Battlefield(Battlefield&& moved)
{
    mHorizontalSize=std::move(moved.mHorizontalSize);
    mVerticalSize=std::move(moved.mVerticalSize);
    mBattlefieldArray=std::move(moved.mBattlefieldArray);
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
    for(int j=y-1; j<=y+yOffset+1; j++)
        if(j>=0 and j<mVerticalSize)
            for(int i=x-1; i<=x+xOffset+1; i++)
                if(i>=0 and i<mHorizontalSize)
                {
                    if(mBattlefieldArray[j][i].hasShip())
                        throw std::logic_error("Intersection between ships occured");
                }

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
                mBattlefieldArray[y].emplace_back();
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