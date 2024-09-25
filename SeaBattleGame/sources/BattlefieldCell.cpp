#include"Battlefield.h"
#include<stdexcept>

Battlefield::BattlefieldCell::BattlefieldCell(const BattlefieldCell& copy):
mShipPointer(copy.mShipPointer), mShipSegmentIndex(copy.mShipSegmentIndex),
mStatus(copy.mStatus) {}

Battlefield::BattlefieldCell::BattlefieldCell(BattlefieldCell&& moved):
mShipPointer(moved.mShipPointer), mShipSegmentIndex(moved.mShipSegmentIndex),
mStatus(moved.mStatus)
{
    moved.mShipPointer=nullptr;
    moved.mShipSegmentIndex=-1;
    moved.mStatus=CellStatus::unknown; 
}

Battlefield::BattlefieldCell& Battlefield::BattlefieldCell::operator=(const Battlefield::BattlefieldCell& copy)
{
    if(&copy!=this)
    {
        mShipPointer=copy.mShipPointer;
        mShipSegmentIndex=copy.mShipSegmentIndex;
        mStatus = copy.mStatus;
    }
    return *this;
}

Battlefield::BattlefieldCell& Battlefield::BattlefieldCell::operator=(Battlefield::BattlefieldCell&& moved)
{
    if(&moved!=this)
    {
        mShipPointer=moved.mShipPointer;
        mShipSegmentIndex=moved.mShipSegmentIndex;
        mStatus = moved.mStatus;

        moved.mShipPointer=nullptr;
        moved.mShipSegmentIndex=-1;
        moved.mStatus=CellStatus::unknown; 
    }
    return *this;
}

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