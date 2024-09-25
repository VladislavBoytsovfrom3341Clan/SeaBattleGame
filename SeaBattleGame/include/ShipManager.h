#ifndef SHIP_MANAGER
#define SHIP_MANAGER

#include<utility>
#include<initializer_list>
#include"Battleship.h"
#include"Battlefield.h"

class ShipManager
{
    std::vector<Battleship> mInactiveShipArray;
    std::vector<Battleship> mActiveShipArray;

public:
    ShipManager(std::initializer_list<std::pair<int, int>> shipList);
    int getAliveShipsNumber();
    int getInactiveShipsNumber();
    const std::vector<Battleship>& getInactiveShips() const;
    void setShipToBattlefield(Battlefield& field, int shipIndex, int x, int y, Orientation orientation);
};

#endif