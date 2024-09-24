#ifndef SHIP_MANAGER
#define SHIP_MANAGER

#include<utility>
#include<initializer_list>
#include"Battleship.h"

class ShipManager
{
    std::vector<Battleship> mBattleshipArray;

public:
    ShipManager(std::initializer_list<std::pair<int, int>> shipList);
    int getShipsNumber();
};

#endif