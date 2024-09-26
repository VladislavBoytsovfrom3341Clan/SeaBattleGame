#include "Battleship.h"
#include<stdexcept>
Battleship::BattleshipSegment::BattleshipSegment()
{
    mSegmentCondition=SegmentCondition::intact;
}

void Battleship::BattleshipSegment::takeDamage(const int damage) noexcept
{
    if(damage<=0)
        return;
    if(damage>=2)
        mSegmentCondition=SegmentCondition::destroyed;
    else 
        if(mSegmentCondition == SegmentCondition::intact)
            mSegmentCondition=SegmentCondition::damaged;
        else if(mSegmentCondition == SegmentCondition::damaged)
            mSegmentCondition=SegmentCondition::destroyed;
}

void Battleship::BattleshipSegment::repair(const int val) noexcept
{
    if(val<=0)
        return;
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

SegmentCondition Battleship::BattleshipSegment::getStatus() const noexcept
{
    return mSegmentCondition;
}


Battleship::Battleship(int length):mLength(length)
{
    if(length<minimalShipLength or length>maximalShipLength)
        throw std::logic_error("Invalid ship size");
    for(int i=0; i<mLength; i++)
        mSegments.emplace_back();
}

bool Battleship::isAlive() const noexcept
{
    //returns True if at least one segment is not destroyed
    for(auto segment: mSegments)
        if(segment.getStatus()!=SegmentCondition::destroyed)
            return true;
    return false;
}

SegmentCondition Battleship::getSegmentCondition(const int index) const
{
    if(index<0 or index>=mLength)
        throw std::length_error("Invalid index");
    return mSegments[index].getStatus();
}

int Battleship::getLength() const noexcept
{
    return mLength;
}

void Battleship::damageSegment(const int index, const int damage)
{
    if(index<0 or index>=mLength)
        throw std::length_error("Invalid segment index");
    mSegments[index].takeDamage(damage);
}

void Battleship::repairSegment(const int index, const int val)
{
    if(index<0 or index>=mLength)
        throw std::length_error("Invalid segment index");
    mSegments[index].repair(val);
}

std::vector<SegmentCondition> Battleship::getShipCondition() const
{
    std::vector<SegmentCondition> segments;
    for(auto segment: mSegments)
        segments.push_back(segment.getStatus());
    return segments;
}

