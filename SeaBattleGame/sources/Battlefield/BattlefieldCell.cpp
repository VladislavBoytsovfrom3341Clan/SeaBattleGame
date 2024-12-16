#include"Battlefield.h"
#include<stdexcept>

void Battlefield::BattlefieldCell::setShipSegment(Battleship& ship, const int shipSegmentIndex) noexcept
{
    mShipPointer = &ship;
    mShipSegmentIndex = shipSegmentIndex;
}

bool Battlefield::BattlefieldCell::attackCell(const int damage)
{
    if (mShipPointer == nullptr)
    {
        mStatus = CellStatus::empty;
        return false;
    }
    else
    {
        mShipPointer->damageSegment(mShipSegmentIndex, damage);
        mStatus = CellStatus::shipped;
        if(mShipPointer->isAlive())
            return false;
        return true;
    }
}

CellStatus Battlefield::BattlefieldCell::getStatus() const noexcept
{
    return mStatus;
}

void Battlefield::BattlefieldCell::setStatus(CellStatus st)
{
    mStatus = st;
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

Battleship& Battlefield::BattlefieldCell::getShip()
{
    return *mShipPointer;
}