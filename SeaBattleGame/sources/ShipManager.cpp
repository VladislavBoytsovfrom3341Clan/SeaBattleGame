#include"ShipManager.h"
#include<stdexcept>
#include<iostream>

//gets list of pairs <size, amount>
ShipManager::ShipManager(std::initializer_list<std::pair<int, int>> shipList)
{
    for(auto shipSeries: shipList)
    {
        if(shipSeries.first<minimalShipLength or shipSeries.first>maximalShipLength)
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

const Battleship& ShipManager::getActiveShip(int index) const
{
    if(index<0 or index>=mActiveShipsArray.size())
        throw std::invalid_argument("Invalid ship index");
    return *(mActiveShipsArray[index]);
}


const Battleship& ShipManager::getInactiveShip(int index) const
{
    if(index<0 or index>=mInactiveShipsArray.size())
        throw std::invalid_argument("Invalid ship index");   
    return *(mInactiveShipsArray[index]);
}
void ShipManager::setShipToBattlefield(Battlefield& field, int shipIndex, int x, int y, Orientation orientation)
{
    if(getInactiveShipsNumber() == 0)
        throw std::logic_error("No ships to be set available");
    if (shipIndex<0 or shipIndex>=mInactiveShipsArray.size())
        throw std::invalid_argument("Invalid ship index");
        
    std::cout<<"positioning started\n";
    //may throw an exception from field, so needs to be processed once being called
    field.setShip(mInactiveShipsArray[shipIndex], x, y, orientation);
    std::cout<<"ship set\n";
    std::move(mInactiveShipsArray.begin()+shipIndex, mInactiveShipsArray.begin()+shipIndex+1, std::back_inserter(mActiveShipsArray));
    std::cout<<"move done\n";
    mInactiveShipsArray.erase(mInactiveShipsArray.begin()+shipIndex);
}

ShipManager::~ShipManager()
{
    for(auto ship: mActiveShipsArray)
        delete ship;

    for(auto ship: mInactiveShipsArray)
        delete ship;
}
