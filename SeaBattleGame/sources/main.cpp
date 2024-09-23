#include"Battlefield.h"
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
    Battlefield b(10, 10);
    b.display();
    Battleship s4(4);
    b.setShip(&s4, 1, 1, Orientation::vertical);
    b.attackCell(0, 0);
    b.attackCell(1, 1);
    b.attackCell(1, 2);
    b.attackCell(2, 1);
    b.attackCell(1, 1);
    b.display();
}