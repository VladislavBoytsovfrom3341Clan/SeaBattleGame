#include "Participant.h"


Participant::Participant(GameController* controller, Coords fieldSize, std::initializer_list<std::pair<int, int>> shipList)
{
	mController = controller;
	mShipManager = new ShipManager(shipList);
	mAbilityManager = new AbilityManager();
	mField = new Battlefield(fieldSize.x, fieldSize.y);
}

bool Participant::isAlive()
{
	return (this->mShipManager->getAliveShipsNumber() != 0);
}