#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "Coords.h"
#include"Battleship.h"
#include <string>

constexpr int minimalFieldSize = minimalShipLength;
constexpr int maximalFieldSize = 25;

//enum for players vision of battlefield
enum class CellStatus
{
    unknown,
    empty,
    shipped
};

/**
 * Class contains Cells, which have pointers to placed ships
 * if it were placed (for better accessebility),
 * also Cells in-game status.
 * Allows to place ship at map by segments,
 * attack ship by chosen cell.
 * 
 * In future, there will be methods for 
 * gettng info about the map for drawing one,
 * as some getters for this purpose
*/
class Battlefield
{
    class BattlefieldCell
    {
        //pointer to placed ship if has one
        Battleship* mShipPointer = nullptr;

        //index of segment in the ship (used for getting access to the ship)
        int mShipSegmentIndex = -1;

        //cells in-game status
        CellStatus mStatus = CellStatus::unknown;

    public:

        BattlefieldCell() = default;

        CellStatus getStatus() const noexcept;

        SegmentCondition getSegmentCondition() const;

        void setStatus(CellStatus st);

        //returns True if there is a ship in cell
        bool hasShip() const;

        Battleship& getShip();

        //sets ship segment to the cell, adding a pointer to ship
        void setShipSegment(Battleship& ship, const int shipSegmentIndex) noexcept;

        //method to damage a ship by the segment if there is a ship
        bool attackCell(const int damage);
    };

    //sizes of the field
    int mHorizontalSize;
    int mVerticalSize;

    //field itself
    std::vector<std::vector<BattlefieldCell>> mBattlefieldArray;

    long long calculateControlSum();

public:
    Battlefield() = default;

    Battlefield(const int horizontalSize, const int verticalSize);

    Battlefield(std::vector<std::vector<CellStatus>> init);

    //WARNING: copy constructor does not deep copy ships 
    Battlefield(const Battlefield& copy);

    //move constructor actually moves stuff
    Battlefield(Battlefield&& moved) noexcept;

    //set a ship to a shosen cell
    void setShip(Battleship& ship, Coords coords, Orientation orientation);

    //checks if there if ship in cell at (x, y) 
    bool hasShipAtCell(Coords coords) const;

    Battleship& getShip(Coords coords);

    Coords size() const noexcept;

    //gets a status of cell at (x, y)
    CellStatus getCellStatus(Coords coords) const;

    //gets a Condition of segment of ship if has one
    //may throw an exception if there is no ship
    SegmentCondition getCellShipCondition(Coords coords) const;

    //method for attacking a chosen cell
    bool attackCell(Coords coords, int damage=1);

    //WARNING: copy operator does not deep copy ships
    Battlefield& operator=(const Battlefield& copy);

    //move operator actually moves stuff
    Battlefield& operator=(Battlefield&& moved) noexcept;

    friend std::istream& operator>>(std::istream& is, Battlefield& field);

    friend std::ostream& operator<<(std::ostream& os, Battlefield& field);
};

#endif