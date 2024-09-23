#ifndef BATTLESHIP
#define BATTLESHIP

#include<vector>

extern const int minimalShipLength;
extern const int maximalShipLength;

enum class SegmentCondition
{
    destroyed,
    damaged,
    intact
};

class Battleship
{
    class BattleshipSegment
    {
        SegmentCondition mSegmentCondition;
    public:
        BattleshipSegment();
        void takeDamage(const int damage);
        SegmentCondition getStatus();
    };

    const int mLength;
    std::vector<BattleshipSegment> mSegments;

public:
    Battleship(int length);
    std::vector<SegmentCondition> getShipCondition();
    void damageSegment(const int index, const int damage);
};

#endif