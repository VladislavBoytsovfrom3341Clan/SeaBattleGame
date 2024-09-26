#include"ShipManager.h"
#include<stdexcept>

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
            mShipsArray.push_back({Battleship(shipSeries.first), false});
    }
}

std::vector<Battleship> ShipManager::getInactiveShips() const
{
    std::vector<Battleship> ships;
    for(auto ship: mShipsArray)
        if(ship.second == false)
            ships.push_back(ship.first);
    return ships;
}

std::vector<Battleship> ShipManager::getShips() const
{
    std::vector<Battleship> ships;
    for(auto ship: mShipsArray)
        ships.push_back(ship.first);
    return ships;
}

int ShipManager::getAliveShipsNumber()
{
    int shipNum=0;

    for(auto ship: mShipsArray)
        if(ship.first.isAlive())
            shipNum++;
    return shipNum;
}

void ShipManager::setShipToBattlefield(Battlefield& field, int shipIndex, int x, int y, Orientation orientation)
{
    if(getInactiveShipsNumber() == 0)
        throw std::logic_error("No ships to be set available");
    if (shipIndex<0 or shipIndex>=getInactiveShipsNumber())
        throw std::invalid_argument("Invalid ship index");
    if(mShipsArray[shipIndex].second)
        throw std::logic_error("Ship was already placed to field");
        
    //may throw an exception from field, so needs to be processed once being called
    field.setShip(&mShipsArray[shipIndex].first, x, y, orientation);
    mShipsArray[shipIndex].second=true;
}

int ShipManager::getInactiveShipsNumber()
{
    int shipNum=0;

    for(auto ship: mShipsArray)
        if(ship.second==false)
            shipNum++;
    return shipNum;
}