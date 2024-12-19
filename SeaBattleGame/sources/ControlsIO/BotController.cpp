#include "BotController.h"

#include "ShipPlacementException.h"
#include "AttackCommand.h"


BotController::BotController(Game& game, int index) :
    ParticipantController(game, index) {
}

void BotController::placeShips()
{
    Coords coords = { 0, 0 };
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
}

ICommand* BotController::getAction()
{
    if (mParticipant->mShipManager.getInactiveShipsNumber() > 0)
        this->placeShips();
    int index = 0;
    Coords enemyFieldSize = mObserver.getFieldSize(index);
    Coords coords = { rand() % enemyFieldSize.x, rand() % enemyFieldSize.y };
    ICommand* command = new AttackCommand(index, coords);
    return command;
}
