#include"ShipManager.h"
#include<iostream>
#include"OutOfRangeAttackException.h"
#include"ShipPlacementException.h"

#include "AbilityManager.h"

//no OOP only as DEBUG func
void printShip(const Battleship& ship)
{
    auto segments = ship.getShipCondition();
    std::cout<<"Ship "<<ship.getLength()<<" condition:\n\t";
    for(auto segment: segments)
        std::cout<<int(segment)<<' ';
    std::cout<<'\n';
}

//no OOP only as DEBUG func
void printShipsInManager(const ShipManager& manager)
{
    std::cout<<"Inactive ships in manager: "<<manager.getInactiveShipsNumber()<<'\n';
    for(int i=0; i<manager.getInactiveShipsNumber(); i++)
        printShip(manager.getInactiveShip(i));

    std::cout<<"Active ships in manager: "<<manager.getActiveShipsNumber()<<'\n';
    for(int i=0; i<manager.getActiveShipsNumber(); i++)
        printShip(manager.getActiveShip(i));
}

//WE USE MAIN AS DEBUGGING BASE
int main()
{
    ShipManager myManager({{4, 2}, {2, 3}, {1, 2}});
    printShipsInManager(myManager);

    Battlefield myField(20, 15);
    myField.setShip(myManager.getInactiveShip(0), Coords{1, 2}, Orientation::horizontal);
    try{
    myField.setShip(myManager.getInactiveShip(0), Coords{100, 2}, Orientation::horizontal);
    }
    catch(const ShipPlacementException& e)
    {
        std::cout<<e.what();
    }
    myField.setShip(myManager.getInactiveShip(1), Coords{5, 6}, Orientation::vertical);
    myManager.setShipActive(0);
    myManager.setShipActive(0);
    myField.display();
    printShipsInManager(myManager);
    
    AbilityManager a_manager;

    /**THIS THING WILL BE STORAGED IN PLAYER CLASS AS ONE OF
     * PLAYER CURRENT STATS
     * **/
    int damageMultiplier=1;

    while(!a_manager.empty())
    switch (a_manager.getFirstAbility())
    {
    case AbilityType::DoubleDamage:
    {
        DoubleDamageSettings ddSettings(damageMultiplier);
        a_manager.castLastAbility(ddSettings);
        std::cout<<"DoubleDamage casted\n";
        break;
    }
    case AbilityType::Scanner:
    {
        ScannerSettings scSettings(myField, {4, 2}, a_manager.mHandler);
        a_manager.castLastAbility(scSettings);
        ScannerResult* res = static_cast<ScannerResult*>(a_manager.mHandler.getResult());
        std::cout<<"Scanner casted, result: "<<res->getResult()<<"\n";
        break;
    }
    case AbilityType::Shelling:
    {
        ShellingSettings shSettings(myManager);
        a_manager.castLastAbility(shSettings);
        std::cout<<"Shelling casted\n";
        break;
    }
    default:
        break;
    }

    try
    {
        myField.attackCell({200,2}, damageMultiplier);
    }
    catch(const OutOfRangeAttackException& e)
    {
        std::cout << e.what() << '\n';
    }
    myField.attackCell({2,2}, damageMultiplier);
    myField.display();
    printShipsInManager(myManager);

}