#ifndef BATTLESHIP
#define BATTLESHIP

#include<vector>

constexpr int minimalShipLength = 1;
constexpr int maximalShipLength = 4;


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
        void repair(const int val);
        SegmentCondition getStatus() const noexcept;
    };

    int mLength;
    std::vector<BattleshipSegment> mSegments;

public:
    Battleship() = default;
    explicit Battleship(int length);
    bool isAlive() const noexcept;
    SegmentCondition getSegmentCondition(const int index) const;
    std::vector<SegmentCondition> getShipCondition() const;
    int getLength() const noexcept;
    void damageSegment(const int index, const int damage);
    ~Battleship() = default;
};

#endif