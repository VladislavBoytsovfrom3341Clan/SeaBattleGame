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
        SegmentCondition getStatus() const noexcept;
    };

    int mLength;
    std::vector<BattleshipSegment> mSegments;

public:
    Battleship() = default;
    explicit Battleship(int length);
    bool isAlive() const noexcept;
    SegmentCondition getSegmentCondition(const int index) const;
    int getLength() const noexcept;
    void damageSegment(const int index, const int damage);
    ~Battleship() = default;

};

#endif