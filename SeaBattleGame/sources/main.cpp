#include"ShipManager.h"
#include<iostream>

//no OOP only as debug func
void printShip(const Battleship& ship)
{
    auto segments = ship.getShipCondition();
    std::cout<<"Ship "<<ship.getLength()<<" condition:\n\t";
    for(auto segment: segments)
        std::cout<<int(segment)<<' ';
    std::cout<<'\n';
}

//no OOP only as debug func
void printShipsInManager(const ShipManager& manager)
{
    auto ships = manager.getInactiveShips();
    std::cout<<"Inactive ships in manager\n";
    for(auto ship: ships)
        printShip(ship);
}

int main()
{
    Battleship myShip(3);
    printShip(myShip);
    myShip.damageSegment(1, 1);
    printShip(myShip);

    ShipManager myManager({{4, 1}, {2, 3}, {1, 2}});
    printShipsInManager(myManager);

    Battlefield myField(20, 15);
    myManager.setShipToBattlefield(myField, 0, 3, 4, Orientation::horizontal);
    printShipsInManager(myManager);
    myField.attackCell(3, 4);
    myField.attackCell(6, 4);
    myField.attackCell(2, 4);
    myField.attackCell(7, 4);

    myField.display();
}