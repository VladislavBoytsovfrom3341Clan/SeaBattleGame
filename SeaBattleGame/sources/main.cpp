#include"ShipManager.h"
#include<iostream>

int main()
{
    
    ShipManager ms({{1, 4}});
    Battlefield f(10, 10);
    ms.setShipToBattlefield(f, 0, 0, 0, Orientation::vertical);
    f.attackCell(0, 0);
    f.display();

    Battlefield g(f);
    ms.setShipToBattlefield(g, 0, 2, 2, Orientation::vertical);
    g.attackCell(2, 2);
    f.attackCell(2, 2);
    f.display();
    g.display();
}