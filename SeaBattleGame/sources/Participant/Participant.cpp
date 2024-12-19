#include "Participant.h"

#include <iostream>
Participant::Participant(Coords fieldSize, std::vector<std::pair<int, int>> shipList) :
	mShipManager(shipList), mField(fieldSize.x, fieldSize.y) {}

Participant::Participant(Battlefield field, std::vector<Battleship*> inactive, std::vector<Battleship*> active) :
	mField(field), mShipManager(inactive, active) {}

bool Participant::isAlive() const
{
	return (mShipManager.getAliveShipsNumber() > 0);
}

bool Participant::isReady() const
{
	return mShipManager.getInactiveShipsNumber() == 0;
}