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
    std::vector<Battleship*> mInactiveShipsArray;
    std::vector<Battleship*> mActiveShipsArray;

public:

    //gets list of pairs <shipLength, amount>, places all to inactive ships
    ShipManager(std::initializer_list<std::pair<int, int>> shipList);

    int getShipsNumber() const noexcept;

    int getAliveShipsNumber() const noexcept;

    int getInactiveShipsNumber() const noexcept;

    int getActiveShipsNumber() const noexcept;

    const Battleship& getActiveShip(int index) const;

    const Battleship& getInactiveShip(int index) const;

    //method will be used by player/bot interface to call fields method
    void setShipToBattlefield(Battlefield& field, int shipIndex, int x, int y, Orientation orientation);

    ~ShipManager();
};

#endif