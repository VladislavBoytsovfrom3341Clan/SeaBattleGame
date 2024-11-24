#include"ShipManager.h"
#include<stdexcept>
#include<iostream>

//gets list of pairs <size, amount>
ShipManager::ShipManager(std::initializer_list<std::pair<int, int>> shipList)
{
    for(auto& shipSeries: shipList)
    {
        if(shipSeries.first<minimalShipLength || shipSeries.first>maximalShipLength)
            throw std::invalid_argument("Invalid ship length");
        if(shipSeries.second<=0)
            throw std::invalid_argument("Ships number must be greater than zero");

        for(int i=0; i<shipSeries.second; i++)
        {
            Battleship* newShip = new Battleship(shipSeries.first);
            mInactiveShipsArray.push_back(newShip);
        }
    }
}

int ShipManager::getShipsNumber() const noexcept
{
    return mInactiveShipsArray.size() + mActiveShipsArray.size();
}

int ShipManager::getAliveShipsNumber() const noexcept
{
    int shipNum=0;

    for(auto ship: mActiveShipsArray)
        if(ship->isAlive())
            shipNum++;
    for(auto ship: mInactiveShipsArray)
        if(ship->isAlive())
            shipNum++;
    return shipNum;
}

int ShipManager::getInactiveShipsNumber() const noexcept
{
    return mInactiveShipsArray.size();
}

int ShipManager::getActiveShipsNumber() const noexcept
{
    return mActiveShipsArray.size();
}

Battleship& ShipManager::getActiveShip(int index) const
{
    if(index<0 || index>=mActiveShipsArray.size())
        throw std::invalid_argument("Invalid ship index");
    return *(mActiveShipsArray[index]);
}


Battleship& ShipManager::getInactiveShip(int index) const
{
    if(index<0 || index>=mInactiveShipsArray.size())
        throw std::invalid_argument("Invalid ship index");   
    return *(mInactiveShipsArray[index]);
}

void ShipManager::setShipActive(int index)
{
    if (index<0 || index>=mInactiveShipsArray.size())
        throw std::invalid_argument("Invalid ship index");
    std::move(mInactiveShipsArray.begin()+index, mInactiveShipsArray.begin()+index+1, std::back_inserter(mActiveShipsArray));
    mInactiveShipsArray.erase(mInactiveShipsArray.begin()+index);
}

void ShipManager::setShipInactive(int index)
{
    if (index<0 || index>=mActiveShipsArray.size())
        throw std::invalid_argument("Invalid ship index");
    std::move(mActiveShipsArray.begin()+index, mActiveShipsArray.begin()+index+1, std::back_inserter(mInactiveShipsArray));
    mActiveShipsArray.erase(mActiveShipsArray.begin()+index);
}

ShipManager::~ShipManager()
{
    for(auto ship: mActiveShipsArray)
        delete ship;

    for(auto ship: mInactiveShipsArray)
        delete ship;
}
