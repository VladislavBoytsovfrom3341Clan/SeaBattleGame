#include"ShipManager.h"
#include<stdexcept>
#include<iostream>

//gets list of pairs <size, amount>
ShipManager::ShipManager(std::vector<std::pair<int, int>> shipList)
{
    for(auto& shipSeries: shipList)
    {
        if(shipSeries.first<minimalShipLength || shipSeries.first>maximalShipLength)
            throw std::invalid_argument("Invalid ship length");
        if(shipSeries.second<=0)
            throw std::invalid_argument("Ships number must be greater than zero");

        for(int i=0; i<shipSeries.second; i++)
        {
            mInactiveShipsVector.push_back( std::make_shared<Battleship>(shipSeries.first));
        }
    }
}

ShipManager::ShipManager(std::vector<std::shared_ptr<Battleship>> inactive, std::vector<std::shared_ptr<Battleship>> active)
{
    mInactiveShipsVector = inactive;
    mActiveShipsVector = active;
}

ShipManager::ShipManager(const ShipManager& copy)
{
    mActiveShipsVector = copy.mActiveShipsVector;
    mInactiveShipsVector = copy.mInactiveShipsVector;
}

int ShipManager::getShipsNumber() const noexcept
{
    return mInactiveShipsVector.size() + mActiveShipsVector.size();
}

//Iterates through all ships, counts alive by Battleship::isAlive()
int ShipManager::getAliveShipsNumber() const noexcept
{
    int shipNum=0;

    for (auto& inactiveShip : mInactiveShipsVector)
        if (inactiveShip->isAlive())
            shipNum++;
    for (auto& activeShip : mActiveShipsVector)
        if (activeShip->isAlive())
            shipNum++;
    
    return shipNum;
}

int ShipManager::getInactiveShipsNumber() const noexcept
{
    return mInactiveShipsVector.size();
}

int ShipManager::getActiveShipsNumber() const noexcept
{
    return mActiveShipsVector.size();
}

//returns i-th ship in mActiveShipsVector
Battleship& ShipManager::getActiveShip(int index) const
{
    if (index < 0 || index >= mActiveShipsVector.size())
        throw std::invalid_argument("Invalid ship index");
    return *(mActiveShipsVector[index]);
}

//returns i-th ship in mInactiveShipsVector
Battleship& ShipManager::getInactiveShip(int index) const
{
    if (index < 0 || index >= mInactiveShipsVector.size())
        throw std::invalid_argument("Invalid ship index");
    return *(mInactiveShipsVector[index]);
}

//Moves i-th ship from mInactiveShipsVector to end of mActiveShipsVector
void ShipManager::setShipActive(int index)
{
    if (index < 0 || index >= mInactiveShipsVector.size())
        throw std::invalid_argument("Invalid ship index");
    std::move(mInactiveShipsVector.begin() + index, mInactiveShipsVector.begin() + index + 1, std::back_inserter(mActiveShipsVector));
    mInactiveShipsVector.erase(mInactiveShipsVector.begin() + index);
}

//Moves i-th ship from mActiveShipsVector to end of mInactiveShipsVector
void ShipManager::setShipInactive(int index)
{
    if (index < 0 || index >= mActiveShipsVector.size())
        throw std::invalid_argument("Invalid ship index");
    std::move(mActiveShipsVector.begin() + index, mActiveShipsVector.begin() + index + 1, std::back_inserter(mInactiveShipsVector));
    mActiveShipsVector.erase(mActiveShipsVector.begin() + index);
}

