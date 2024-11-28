#include "BotController.h"

#include "ShipPlacementException.h"
#include "AttackCommand.h"

#include <iostream>

void BotController::placeShips()
{
    Coords coords = { 0, 0 };
    std::cout << "Init ship placement\n";
    while (mParticipant->mShipManager.getInactiveShipsNumber() > 0)
    {
        try
        {
            Battleship& ship = mParticipant->mShipManager.getInactiveShip(0);
            mParticipant->mField.setShip(ship, { coords.x, coords.y }, Orientation::vertical);
            mParticipant->mShipManager.setShipActive(0);
        }
        catch (ShipPlacementException& e)
        {
            std::cout << e.what();
        }
        coords.x += 2;
    }
    std::cout << "Ended with " << mParticipant->mShipManager.getActiveShipsNumber() << '\n';
}

ICommand* BotController::getAction()
{
    if (mParticipant->mShipManager.getInactiveShipsNumber() > 0)
        this->placeShips();
    int index = 0;
    Coords coords = { rand() % 5, rand() % 5 };
    ICommand* command = new AttackCommand(index, coords);
    std::cout << "\nBot made an attack command!\n";
    return command;
}
