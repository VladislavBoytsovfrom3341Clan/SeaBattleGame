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
	Battlefield* mField;
	ShipManager* mShipManager;
	AbilityManager* mAbilityManager;
	class GameController* mController;

	Participant(class GameController* controller, Coords fieldSize, std::initializer_list<std::pair<int, int>> shipList);

	bool isAlive();

	virtual void placeShips() = 0;

	virtual void act() = 0;

	virtual ICommand* getAction() = 0;
};
#endif