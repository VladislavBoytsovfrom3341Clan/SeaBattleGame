#include"ShipManager.h"
#include<iostream>

#include "AbilityManager.h"

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

void useAbility(AbilityManager& manager)
{
    
}

int main()
{
    ShipManager myManager({{4, 2}, {2, 3}, {1, 2}});
    printShipsInManager(myManager);

    Battlefield myField(20, 15);
    myField.setShip(myManager.getInactiveShip(0), Coords{1, 2}, Orientation::horizontal);
    myField.setShip(myManager.getInactiveShip(1), Coords{5, 6}, Orientation::vertical);
    myManager.setShipActive(0);
    myManager.setShipActive(0);
    myField.display();
    printShipsInManager(myManager);
    
    AbilityManager myAbilities;


    int i=0;
    while(!myAbilities.empty() and i<15)
    {
        IAbility& ab = myAbilities.getAbility();
        if(typeid(ab) == typeid(DoubleDamage))
        {
            DoubleDamage& dd = dynamic_cast<DoubleDamage&>(ab);
            dd.set(myField, Coords{1, 2});
            dd.cast();
        }
        else if(typeid(ab) == typeid(Shelling))
        {
            Shelling& sh = dynamic_cast<Shelling&>(ab);
            sh.set(myManager);
            sh.cast();
        }
        else if(typeid(ab) == typeid(Scanner))
        {
            Scanner& sc = dynamic_cast<Scanner&>(ab);
            sc.set(myField, Coords{0, 1});
            sc.cast();
            std::cout<<"Scanner detected "<<sc.getSegNum()<<'\n';
        }
        myAbilities.popAbility();
        i++;
        myAbilities.addAbility();
    }

    myField.display();
    printShipsInManager(myManager);

}