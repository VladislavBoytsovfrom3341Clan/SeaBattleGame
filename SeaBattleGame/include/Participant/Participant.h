#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "Battlefield.h"
#include "ShipManager.h"
#include "AbilityManager.h"
#include "ICommand.h"
//#include "GameController.h"

#include <vector>

struct Participant
{
	Battlefield mField;
	ShipManager mShipManager;
	AbilityManager mAbilityManager;

	Participant(Coords fieldSize, std::vector<std::pair<int, int>> shipList);

	bool isAlive();

	virtual void placeShips() = 0;

	virtual ICommand* getAction() = 0;
};
#endif