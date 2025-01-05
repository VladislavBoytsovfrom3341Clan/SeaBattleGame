#ifndef SHIP_MANAGER
#define SHIP_MANAGER

#include<utility>          //for std::pair
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
    /*
    * Vector of ships storaged in manager; 
    * bool stays for false = inactive / true = active
    */
    std::vector<std::pair<Battleship*, bool>> mShips;

public:
    ShipManager() = default;

    //gets list of pairs <shipLength, amount>, places all to inactive ships
    ShipManager(std::vector<std::pair<int, int>> shipList);

    ShipManager(std::vector<Battleship*> inactive, std::vector<Battleship*> active);

    ShipManager(const ShipManager& copy);

    int getShipsNumber() const noexcept;

    int getAliveShipsNumber() const noexcept;

    int getInactiveShipsNumber() const noexcept;

    int getActiveShipsNumber() const noexcept;

    Battleship& getActiveShip(int index) const;

    Battleship& getInactiveShip(int index) const;

    void setShipActive(int index);

    void setShipInactive(int index);

    ~ShipManager();
};

#endif