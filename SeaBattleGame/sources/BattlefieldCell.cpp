#include"Battlefield.h"
#include<stdexcept>

void Battlefield::BattlefieldCell::setShipSegment(Battleship* const shipPointer, const int shipSegmentIndex) noexcept
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