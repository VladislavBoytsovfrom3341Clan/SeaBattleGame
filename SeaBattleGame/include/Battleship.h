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

    int mLength;
    std::vector<BattleshipSegment> mSegments;

public:
    Battleship() = default;
    Battleship(int length);
    bool isAlive() const;
    SegmentCondition getSegmentCondition(const int index);
    int getLength();
    void damageSegment(const int index, const int damage);
    ~Battleship() = default;

};

#endif