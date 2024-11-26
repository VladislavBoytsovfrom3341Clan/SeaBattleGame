#include "Participant.h"

#include <iostream>
Participant::Participant(Coords fieldSize, std::vector<std::pair<int, int>> shipList) :
	mShipManager(shipList), mField(fieldSize.x, fieldSize.y) {}

bool Participant::isAlive()
{
	return (mShipManager.getAliveShipsNumber() != 0);
}