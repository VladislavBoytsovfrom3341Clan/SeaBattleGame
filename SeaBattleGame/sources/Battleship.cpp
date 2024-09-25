#include "Battleship.h"
#include<iostream>

const int minimalShipLength=1;
const int maximalShipLength=4;

Battleship::BattleshipSegment::BattleshipSegment()
{
    mSegmentCondition=SegmentCondition::intact;
}

void Battleship::BattleshipSegment::takeDamage(const int damage)
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

bool Battleship::isAlive() const
{
    for(auto segment: mSegments)
        if(segment.getStatus()!=SegmentCondition::destroyed)
            return true;
    return false;
}

SegmentCondition Battleship::getSegmentCondition(const int index)
{
    if(index<0 or index>=mLength)
        throw std::length_error("Invelid index");
    return mSegments[index].getStatus();
}

int Battleship::getLength()
{
    return mLength;
}

void Battleship::damageSegment(const int index, const int damage)
{
    if(index<0 or index>=maximalShipLength)
        throw std::length_error("Invalid segment index");
    mSegments[index].takeDamage(damage);
}
