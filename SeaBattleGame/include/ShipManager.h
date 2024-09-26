#ifndef SHIP_MANAGER
#define SHIP_MANAGER

#include<utility>          //for std::pair
#include<initializer_list>
#include"Battleship.h"
#include"Battlefield.h"

/**
 * This class contains all placed-on-field ships
 * and yet not placed ones, also taking responsibility for
 * calling fields placeShip methods.
 * It will be used to count how many ships there are left,
 * and then to end up the game
*/
class ShipManager
{
    //not placed on field ships
    std::vector<Battleship> mInactiveShipArray;

    //placed on field ships
    std::vector<Battleship> mActiveShipArray;

public:

    //gets list of pairs <shipLength, amount>, places all to inactive ships
    ShipManager(std::initializer_list<std::pair<int, int>> shipList);

    int getAliveShipsNumber();

    int getInactiveShipsNumber();

    //returns link to const vector of all inactive ships
    const std::vector<Battleship>& getInactiveShips() const;

    //nethod will be used by player/bot interface to call fields method
    void setShipToBattlefield(Battlefield& field, int shipIndex, int x, int y, Orientation orientation);
};

#endif