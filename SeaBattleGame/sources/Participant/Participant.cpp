#include "Participant.h"

#include <iostream>
Participant::Participant(Coords fieldSize, std::vector<std::pair<int, int>> shipList)
{
	mShipManager = new ShipManager(shipList);
	mAbilityManager = new AbilityManager();
	mField = new Battlefield(fieldSize.x, fieldSize.y);
}

bool Participant::isAlive()
{
	return (this->mShipManager->getAliveShipsNumber() != 0);
}