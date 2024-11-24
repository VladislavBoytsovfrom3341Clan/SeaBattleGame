#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "Battlefield.h"
#include "ShipManager.h"
#include "AbilityManager.h"

#include <vector>

struct Participant
{
	Battlefield* mField;
	ShipManager* mShipManager;
	AbilityManager* mAbilityManager;

	Participant(Coords fieldSize, std::initializer_list<std::pair<int, int>> shipList);

	bool isAlive();

	virtual void placeShips() = 0;

	virtual int getAction() = 0;
};
#endif