#ifndef BATTLESHIP
#define BATTLESHIP

#include<vector>

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
        void takeDamage(int damage);
        SegmentCondition getStatus();
    };

    const int mLength;
    std::vector<BattleshipSegment> segments;

public:
    Battleship(int length);
};

#endif