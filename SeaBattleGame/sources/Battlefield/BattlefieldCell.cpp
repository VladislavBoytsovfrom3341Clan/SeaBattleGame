#include"Battlefield.h"
#include<stdexcept>

void Battlefield::BattlefieldCell::setShipSegment(Battleship& ship, const int shipSegmentIndex) noexcept
{
    mShipPointer = &ship;
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

CellStatus Battlefield::BattlefieldCell::getStatus() const noexcept
{
    return mStatus;
}

SegmentCondition Battlefield::BattlefieldCell::getSegmentCondition() const
{
    if (mShipPointer == nullptr)
        throw std::logic_error("No ship handles this cell");
    return mShipPointer->getSegmentCondition(mShipSegmentIndex);
}

bool Battlefield::BattlefieldCell::hasShip() const
{
    return mShipPointer != nullptr;
}