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
            mBattleshipArray.push_back(newShip);
        }
    }
}

int ShipManager::getShipsNumber()
{
    int shipNum=0;
    for(auto ship: mBattleshipArray)
        if(ship.isAlive())
            shipNum++;
    return shipNum;
}