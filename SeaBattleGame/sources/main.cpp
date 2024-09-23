#include"Battleship.h"
#include<iostream>

void printShip(Battleship& ship)
{
    std::cout<<"\n";
    std::vector<SegmentCondition> s1 = ship.getShipCondition();
    for(auto i: s1)
    {
        std::cout<<int(i)<<" ";
    }
    std::cout<<"\n";
}

int main()
{
    Battleship ms(4);
    printShip(ms);
    ms.damageSegment(0, 1);
    ms.damageSegment(2, 2);
    printShip(ms);
}