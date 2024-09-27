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

    ShipManager myManager({{4, 2}, {2, 3}, {1, 2}});
    printShipsInManager(myManager);

    Battlefield myField(20, 15);
    myManager.setShipToBattlefield(myField, 0, 1, 2, Orientation::horizontal);
    printShipsInManager(myManager);
    myManager.setShipToBattlefield(myField, 1, 10, 1, Orientation::vertical);
    printShipsInManager(myManager);
    myField.display();
    myField.attackCell(1, 1);
    myField.attackCell(2, 1);
    myField.attackCell(2, 2);
    myField.attackCell(1, 2);

    myField.attackCell(10, 1);
    myField.attackCell(10, 2);
    myField.attackCell(10, 3);
    myField.attackCell(10, 4);
    myField.attackCell(10, 5);

    myField.display();
}