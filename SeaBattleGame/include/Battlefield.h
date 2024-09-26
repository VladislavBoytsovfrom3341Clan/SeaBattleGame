#ifndef BATTLEFIELD
#define BATTLEFIELD

#include"Battleship.h"

constexpr int minimalFieldSize = minimalShipLength;
constexpr int maximalFieldSize = 25;

enum class CellStatus
{
    unknown,
    empty,
    shipped
};

enum class Orientation
{
    horizontal, 
    vertical
};

class Battlefield
{
    class BattlefieldCell
    {
        Battleship* mShipPointer = nullptr;
        int mShipSegmentIndex = -1;
        CellStatus mStatus = CellStatus::unknown;
    public:
        BattlefieldCell() = default;
        CellStatus getStatus();
        SegmentCondition getSegmentCondition();
        bool hasShip();
        void setShipSegment(Battleship* const shipPointer, const int shipSegmentIndex) noexcept;
        void attackCell(const int damage);
    };
    int mHorizontalSize;
    int mVerticalSize;
    std::vector<std::vector<BattlefieldCell>> mBattlefieldArray;

public:
    Battlefield(const int horizontalSize, const int verticalSize);
    Battlefield(const Battlefield& copy);
    Battlefield(Battlefield&& moved);
    void setShip(Battleship* ship, int x, int y, Orientation orientation);
    void display();
    void attackCell(int x, int y);

    Battlefield& operator=(const Battlefield& copy);
    Battlefield& operator=(Battlefield&& moved);
};

#endif