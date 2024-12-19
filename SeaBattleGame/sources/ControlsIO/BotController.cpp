#include "BotController.h"

#include "ShipPlacementException.h"
#include "AttackCommand.h"
#include "PlaceShipCommand.h"


BotController::BotController(Game& game, int index) :
    ParticipantController(game, index) {
}

ICommand* BotController::placeShip()
{
    ICommand* place = new PlaceShipCommand(0, lastStand, Orientation::vertical);
    lastStand.x += 2;
    return place;
}

ICommand* BotController::getAction()
{
    if (mParticipant->mShipManager.getInactiveShipsNumber() > 0)
        return this->placeShip();
    int index = 0;
    Coords enemyFieldSize = mObserver.getFieldSize(index);
    Coords coords = { rand() % enemyFieldSize.x, rand() % enemyFieldSize.y };
    ICommand* command = new AttackCommand(index, coords);
    return command;
}
