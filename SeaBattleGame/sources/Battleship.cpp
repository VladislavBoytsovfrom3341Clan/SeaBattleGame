#include "Battleship.h"
#include<iostream>

const int minimalShipLength=1;
const int maximalShipLength=4;

Battleship::BattleshipSegment::BattleshipSegment()
{
    mSegmentCondition=SegmentCondition::intact;
}

void Battleship::BattleshipSegment::takeDamage(int damage)
{
    if(damage>=2)
        mSegmentCondition=SegmentCondition::destroyed;
    else 
        if(damage>0)
        {
            if(mSegmentCondition == SegmentCondition::intact)
                mSegmentCondition=SegmentCondition::damaged;
            else if(mSegmentCondition == SegmentCondition::damaged)
                mSegmentCondition=SegmentCondition::destroyed;
        }
}

SegmentCondition Battleship::BattleshipSegment::getStatus()
{
    return mSegmentCondition;
}


Battleship::Battleship(int length):mLength(length)
{
    if(length<minimalShipLength or length>maximalShipLength)
        throw std::logic_error("Invalid ship size");
    for(int i=0; i<mLength; i++)
    {
        BattleshipSegment newSegment;
        mSegments.push_back(newSegment);
    }
}