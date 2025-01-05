#ifndef BATTLESHIP
#define BATTLESHIP

#include<vector>

#include <iostream>
#include <fstream>
#include "Coords.h"

constexpr int minimalShipLength = 1;
constexpr int maximalShipLength = 4;

/**
 * enum, describing current condition of 
 * particular ship segment
**/
enum SegmentCondition
{
    destroyed = 0,
    damaged = 1,
    intact = 2
};

/**
 * Class Battleship contains vector of
 * BattleshipSegment and is used for
 * memorizing taken damage.
 * In future, it will contain 
 * own textures for GUI 
*/
class Battleship
{
    class BattleshipSegment
    {
        SegmentCondition mSegmentCondition;
    public:
        BattleshipSegment();

        BattleshipSegment(SegmentCondition s);

        void setCondition(int i);

        //method to take positive damage for segment
        void takeDamage(const int damage) noexcept;

        //"increase" ship condition by val
        void repair(const int val) noexcept;

        //returns condition of the segment
        SegmentCondition getStatus() const noexcept;

        long calculateControlSum();
    };

    int mLength = 0;
    std::vector<BattleshipSegment> mSegments;
    Coords mPosition = {-1, -1};
    Orientation mOrnt = Orientation::horizontal;
    
    long calculateControlSum();

public:
    Battleship() = default;
    explicit Battleship(int length);

    Battleship(Coords coords, Orientation ornt, std::vector<int> init);

    void setPosition(Coords coords, Orientation ornt);

    Coords getPosition() const noexcept;

    Orientation getOrientation() const noexcept;

    //checks if there are not destroyed segments
    bool isAlive() const noexcept;

    //returns condition of <index> segment in ship
    SegmentCondition getSegmentCondition(const int index) const;

    //returns all segments condition in vector
    std::vector<SegmentCondition> getShipCondition() const;

    //returns ships length
    int getLength() const noexcept;

    //damages <index> segment by <damage>
    void damageSegment(const int index, const int damage);

    //repairs ship <index> segment by <val>
    void repairSegment(const int index, const int val);

    friend std::istream& operator>>(std::istream& is, Battleship& ship);

    friend std::ostream& operator<<(std::ostream& os, Battleship& ship);
    
    ~Battleship() = default;
};

#endif