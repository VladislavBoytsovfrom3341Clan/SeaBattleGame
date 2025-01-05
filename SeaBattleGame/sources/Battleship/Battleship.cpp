#include "Battleship.h"
#include<stdexcept>

#include "Coords.h"

Battleship::BattleshipSegment::BattleshipSegment()
{
    mSegmentCondition=SegmentCondition::intact;
}

Battleship::BattleshipSegment::BattleshipSegment(SegmentCondition s)
{
    mSegmentCondition = s;
    mSegmentCondition = s;
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

//uses 11, 13 and 17 as prime numbers
long Battleship::BattleshipSegment::calculateControlSum()
{
    switch (mSegmentCondition)
    {
    case destroyed:
        return 11;
        break;
    case damaged:
        return 13;
        break;
    case intact:
        return 17;
        break;
    default:
        return 1;
    }
}

Battleship::Battleship(int length):mLength(length)
{
    mPosition = { 0, 0 };
    if(length<minimalShipLength || length>maximalShipLength)
        throw std::logic_error("Invalid ship size");
    for(int i=0; i<mLength; i++)
        mSegments.emplace_back();
}

Battleship::Battleship(Coords coords, Orientation ornt, std::vector<int> init)
{
    mLength = init.size();
    mSegments.resize(mLength);
    for (int i = 0; i < mLength; i++)
        mSegments[i].setCondition(init[i]);
    mPosition = coords;
    mOrnt = ornt;
}

void Battleship::setPosition(Coords coords, Orientation ornt)
{
    mPosition = coords;
    mOrnt = ornt;
}

Coords Battleship::getPosition() const noexcept
{
    return mPosition;
}

Orientation Battleship::getOrientation() const noexcept
{
    return mOrnt;
}

bool Battleship::isAlive() const noexcept
{
    //returns True if at least one segment is not destroyed
    for(auto& segment: mSegments)
        if(segment.getStatus()!=SegmentCondition::destroyed)
            return true;
    return false;
}

SegmentCondition Battleship::getSegmentCondition(const int index) const
{
    if(index<0 || index>=mLength)
        throw std::length_error("Invalid index");
    return mSegments[index].getStatus();
}

int Battleship::getLength() const noexcept
{
    return mLength;
}

void Battleship::damageSegment(const int index, const int damage)
{
    if(index<0 || index>=mLength)
    {
        throw std::length_error("Invalid segment index");
    }
    mSegments[index].takeDamage(damage);
}

void Battleship::repairSegment(const int index, const int val)
{
    if(index<0 || index>=mLength)
        throw std::length_error("Invalid segment index");
    mSegments[index].repair(val);
}

std::vector<SegmentCondition> Battleship::getShipCondition() const
{
    std::vector<SegmentCondition> segments;
    for(auto& segment: mSegments)
        segments.push_back(segment.getStatus());
    return segments;
}

void Battleship::BattleshipSegment::setCondition(int i)
{
    if (i == 0)
        mSegmentCondition = SegmentCondition::destroyed;
    else if (i == 1)
        mSegmentCondition = SegmentCondition::damaged;
    else
        mSegmentCondition = SegmentCondition::intact;
}

//all magic number are prime numbers used for coding
long Battleship::calculateControlSum()
{
    long sum = 0;
    for (int i=0; i<mSegments.size(); i++)
    {
        sum += (i + 1) * mSegments[i].calculateControlSum();
    }
    if (mOrnt == Orientation::horizontal)
        sum += 23;
    else
        sum += 29;
    sum += mPosition.x * 5 + mPosition.y * 7;
    return sum;
}

std::istream& operator>>(std::istream& is, Battleship& ship)
{
    long readSum = 0;
    is >> readSum;
    int orientation;
    is >> orientation;
    if (orientation == 0)
        ship.mOrnt = Orientation::horizontal;
    else
        ship.mOrnt = Orientation::vertical;
    is >> ship.mPosition.x >> ship.mPosition.y >> ship.mLength;
    ship.mSegments.resize(ship.mLength);
    for (int i = 0; i < ship.mLength; i++)
    {
        int seg;
        is >> seg;
        ship.mSegments[i].setCondition(seg);
    }
    if (readSum != ship.calculateControlSum())
        throw std::runtime_error("File reading error: invalid ship control sum\n");
    return is;
}

std::ostream& operator<<(std::ostream& os, Battleship& ship)
{
    os << ship.calculateControlSum()<<'\n';
    if (ship.mOrnt == Orientation::horizontal)
        os << 0;
    else
        os << 1;
    os<<' ' << ship.mPosition.x<<' ' << ship.mPosition.y<<' ' << ship.mLength;
    for (int i = 0; i < ship.mLength; i++)
    {
        os << ' ';
        SegmentCondition seg = ship.mSegments[i].getStatus();
        if (seg == SegmentCondition::destroyed)
            os << 0;
        else if (seg == SegmentCondition::damaged)
            os << 1;
        else
            os << 2;
    }
    os << '\n';
    return os;
}

Battleship::~Battleship()
{
    
}