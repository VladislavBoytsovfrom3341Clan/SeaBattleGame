#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "Battlefield.h"
#include "ShipManager.h"
#include "AbilityManager.h"

#include <vector>

struct Participant
{
	Battlefield mField;
	ShipManager mShipManager;
	AbilityManager mAbilityManager;
	AbilityResultHandler mHandler;
	int mDamageMultiplier = 1;

	Participant() = default;

	Participant(Battlefield field, std::vector<std::shared_ptr<Battleship>> inactive, std::vector<std::shared_ptr<Battleship>> active);

	Participant(Coords fieldSize, std::vector<std::pair<int, int>> shipList);

	bool isAlive() const;

	virtual bool isReady() const;

	virtual ~Participant();
};
#endif