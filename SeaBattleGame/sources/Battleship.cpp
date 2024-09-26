#include "Battleship.h"
#include<iostream>

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

SegmentCondition Battleship::BattleshipSegment::getStatus() const noexcept
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

bool Battleship::isAlive() const noexcept
{
    for(auto segment: mSegments)
        if(segment.getStatus()!=SegmentCondition::destroyed)
            return true;
    return false;
}

SegmentCondition Battleship::getSegmentCondition(const int index) const
{
    if(index<0 or index>=mLength)
        throw std::length_error("Invelid index");
    return mSegments[index].getStatus();
}

int Battleship::getLength() const noexcept
{
    return mLength;
}

void Battleship::damageSegment(const int index, const int damage)
{
    if(index<0 or index>=maximalShipLength)
        throw std::length_error("Invalid segment index");
    mSegments[index].takeDamage(damage);
}

void Battleship::BattleshipSegment::repair(const int val)
{
    if(val>0)
    {
        if(val==1)
        {
            if(mSegmentCondition==SegmentCondition::destroyed)
                mSegmentCondition=SegmentCondition::damaged;
            else 
                mSegmentCondition=SegmentCondition::intact;
        }
        else
            mSegmentCondition=SegmentCondition::intact;
    }
}

std::vector<SegmentCondition> Battleship::getShipCondition() const
{
    std::vector<SegmentCondition> segments;
    for(auto segment: mSegments)
        segments.push_back(segment.getStatus());
    return segments;
}
