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
    std::cout<<"Inactive ships in manager: "<<manager.getInactiveShipsNumber()<<'\n';
    for(int i=0; i<manager.getInactiveShipsNumber(); i++)
        printShip(manager.getInactiveShip(i));

    std::cout<<"Active ships in manager: "<<manager.getActiveShipsNumber()<<'\n';
    for(int i=0; i<manager.getActiveShipsNumber(); i++)
        printShip(manager.getActiveShip(i));
}

int main()
{
    ShipManager myManager({{4, 2}, {2, 3}, {1, 2}});
    printShipsInManager(myManager);

    Battlefield myField(20, 15);
    myManager.setShipToBattlefield(myField, 0, 1, 2, Orientation::horizontal);
    myManager.setShipToBattlefield(myField, 0, 5, 6, Orientation::vertical);
    myField.display();
    printShipsInManager(myManager);
    myField.attackCell(1, 1);
    myField.attackCell(1, 2);
    myField.attackCell(2, 2);
    myField.attackCell(3, 2);
    myField.attackCell(4, 2);
    myField.attackCell(5, 6);
    myField.attackCell(5, 8);
    myField.display();
    printShipsInManager(myManager);

}