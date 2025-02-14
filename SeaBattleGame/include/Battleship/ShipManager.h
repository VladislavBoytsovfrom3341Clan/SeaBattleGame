#ifndef SHIP_MANAGER
#define SHIP_MANAGER

#include<utility>          //for std::pair
#include"Battleship.h"
#include"Battlefield.h"

#include <memory>

/**
 * This class contains all placed-on-field ships
 * and yet not placed ones, also taking responsibility for
 * calling fields placeShip methods.
 * It will be used to count how many ships there are left
 * and then to end up the game
*/
class ShipManager
{
    //vector of inactive ships (aka not placed on map)
    std::vector<std::shared_ptr<Battleship>> mInactiveShipsVector;

    //vector of active ships (aka placed on map)
    std::vector<std::shared_ptr<Battleship>> mActiveShipsVector;

public:
    ShipManager() = default;

    //gets list of pairs <shipLength, amount>, places all to inactive ships
    ShipManager(std::vector<std::pair<int, int>> shipList);

    ShipManager(std::vector<std::shared_ptr<Battleship>> inactive, std::vector<std::shared_ptr<Battleship>> active);

    ShipManager(const ShipManager& copy);

    int getShipsNumber() const noexcept;

    int getAliveShipsNumber() const noexcept;

    int getInactiveShipsNumber() const noexcept;

    int getActiveShipsNumber() const noexcept;

    //Returns i-th ACTIVE ship
    Battleship& getActiveShip(int index) const;

    //Returns i-th INACTIVE ship
    Battleship& getInactiveShip(int index) const;

    //sets i-th INACTIVE ship as active
    void setShipActive(int index);

    //sets i-th ACTIVE ship as inactive
    void setShipInactive(int index);

    ~ShipManager() = default;
};

#endif