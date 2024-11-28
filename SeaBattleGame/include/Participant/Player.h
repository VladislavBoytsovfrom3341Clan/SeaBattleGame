#ifndef PLAYER_H
#define PLAYER_H

#include "Participant.h"

#include "CLIInput.h"

struct Player : public Participant
{
	//AbilityManager mAbilityManager;

	Player(Coords fieldSize, std::vector<std::pair<int, int>> shipList);
};

#endif