#ifndef BATTLESHIP
#define BATTLESHIP

#include<vector>

constexpr int minimalShipLength = 1;
constexpr int maximalShipLength = 4;

/**
 * enum, describing current condition of 
 * particular ship segment
**/
enum class SegmentCondition
{
    destroyed,
    damaged,
    intact
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

        //method to take positive damage for segment
        void takeDamage(const int damage) noexcept;

        //"increase" ship condition by val
        void repair(const int val) noexcept;

        //returns condition of the segment
        SegmentCondition getStatus() const noexcept;
    };

    int mLength;
    std::vector<BattleshipSegment> mSegments;

public:
    Battleship() = default;
    explicit Battleship(int length);

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
    
    ~Battleship() = default;
};

#endif