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
        {
            Battleship newShip(shipSeries.first);
            mInactiveShipArray.push_back(newShip);
        }
    }
}

const std::vector<Battleship>& ShipManager::getInactiveShips() const
{
    return mInactiveShipArray;
}

int ShipManager::getAliveShipsNumber()
{
    int shipNum=0;
    for(auto ship: mInactiveShipArray)
        if(ship.isAlive())
            shipNum++;
    for(auto ship: mActiveShipArray)
        if(ship.isAlive())
            shipNum++;
    return shipNum;
}

void ShipManager::setShipToBattlefield(Battlefield& field, int shipIndex, int x, int y, Orientation orientation)
{
    if(mInactiveShipArray.size() == 0)
        throw std::logic_error("No ships to be set available");
    if (shipIndex<0 or shipIndex>=mInactiveShipArray.size())
        throw std::invalid_argument("Invalid ship index");
    field.setShip(&mInactiveShipArray.at(shipIndex), x, y, orientation);
    mActiveShipArray.push_back(mInactiveShipArray.at(shipIndex));
    mInactiveShipArray.erase(std::next(mInactiveShipArray.begin(), shipIndex));   
}

int ShipManager::getInactiveShipsNumber()
{
    return mInactiveShipArray.size();
}