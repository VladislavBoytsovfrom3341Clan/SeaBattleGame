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
            mShips.push_back({ std::make_shared<Battleship>(shipSeries.first), false});
        }
    }
}

ShipManager::ShipManager(std::vector<std::shared_ptr<Battleship>> inactive, std::vector<std::shared_ptr<Battleship>> active)
{
    for (auto& ship : inactive)
        mShips.push_back({ ship, false });
    for (auto& ship : active)
        mShips.push_back({ship, true});
}

ShipManager::ShipManager(const ShipManager& copy)
{
    mShips = copy.mShips;
}

int ShipManager::getShipsNumber() const noexcept
{
    return mShips.size();
}

int ShipManager::getAliveShipsNumber() const noexcept
{
    int shipNum=0;

    for(auto& ship: mShips)
        if(ship.first->isAlive())
            shipNum++;
    return shipNum;
}

int ShipManager::getInactiveShipsNumber() const noexcept
{
    int num = 0;
    for (auto& ship : mShips)
        if (ship.second == false)
            num++;
    return num;
}

int ShipManager::getActiveShipsNumber() const noexcept
{
    int num = 0;
    for (auto& ship : mShips)
        if (ship.second == true)
            num++;
    return num;
}

Battleship& ShipManager::getActiveShip(int index) const
{
    int realIndex = 0;
    for (int i = -1; i < index; realIndex++)
    {
        if (realIndex >= mShips.size())
            throw std::invalid_argument("Invalid ship index");
        if (mShips.at(realIndex).second == true)
            i++;
    }
    return *mShips.at(realIndex-1).first;
}


Battleship& ShipManager::getInactiveShip(int index) const
{
    int realIndex = 0;
    for (int i = -1; i < index; realIndex++)
    {
        if (realIndex >= mShips.size())
            throw std::invalid_argument("Invalid ship index");
        if (mShips.at(realIndex).second == false)
            i++;
    }
    return *mShips.at(realIndex-1).first;
}

void ShipManager::setShipActive(int index)
{
    int realIndex = 0;
    for (int i = -1; i < index; realIndex++)
    {
        if (realIndex >= mShips.size())
            throw std::invalid_argument("Invalid ship index");
        if (mShips.at(realIndex).second == false)
            i++;
    }
    mShips.at(realIndex - 1).second = true;
}

void ShipManager::setShipInactive(int index)
{
    int realIndex = 0;
    for (int i = -1; i < index; realIndex++)
    {
        if (realIndex >= mShips.size())
            throw std::invalid_argument("Invalid ship index");
        if (mShips.at(realIndex).second == true)
            i++;
    }
    mShips.at(realIndex - 1).second = false;
}

