#include"ShipManager.h"
#include<iostream>

int main()
{
    
    ShipManager ms({{4, 1}, {3, 2}, {1, 4}});
    Battlefield f(10, 10);
    std::cout<<ms.getInactiveShipsNumber()<<'\n';
    ms.setShipToBattlefield(f, 0 , 1, 1, Orientation::horizontal);
    std::cout<<ms.getInactiveShipsNumber()<<'\n';
    f.attackCell(1, 1);
    f.attackCell(2, 1);
    f.display();
}