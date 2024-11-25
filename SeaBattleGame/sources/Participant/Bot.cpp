#include "Bot.h"

#include "ShipPlacementException.h"
#include "AttackCommand.h"
#include "GameController.h"

#include <iostream>
#include <cstdlib>

void Bot::placeShips()
{
    Coords coords = { 0, 0 };
    while (mShipManager->getInactiveShipsNumber() > 0)
    {
        try
        {
            Battleship& ship = mShipManager->getInactiveShip(0);
            mField->setShip(ship, { coords.x, coords.y }, Orientation::vertical);
            mShipManager->setShipActive(0);
        }
        catch (ShipPlacementException& e)
        {
            std::cout << e.what();
        }
        coords.x += 2;
    }
}

void Bot::act()
{
    mController->acceptCommand(this->getAction());
}

ICommand* Bot::getAction()
{
    int index = 0;
    Coords coords = { rand() % 5, rand() % 5};
    ICommand* command = new AttackCommand(index, coords);
    std::cout << "\nBot made an attack command!\n";
    return command;
}