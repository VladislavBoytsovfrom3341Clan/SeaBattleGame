#ifndef BATTLEFIELD
#define BATTLEFIELD

#include"Battleship.h"

extern const int minimalFieldSize;
extern const int maximalFieldSize;

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
        void setShipSegment(Battleship* shipPointer, const int shipSegmentIndex);
        void attackCell(const int damage);
    };
    const int mHorizontalSize;
    const int mVerticalSize;
    std::vector<std::vector<BattlefieldCell>> mBattlefieldArray;

public:
    Battlefield(const int horizontalSize, const int verticalSize);
    void setShip(Battleship* ship, int x, int y, Orientation orientation);
    void display();
    void attackCell(int x, int y);
};

#endif