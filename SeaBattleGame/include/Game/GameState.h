#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "Coords.h"
#include "GameInfo.h"
#include "IAbilitySettings.h"

#include <vector>

class GameState
{
public:

	virtual void placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation) = 0;

	virtual void attack(int index, Coords coords, int damage) = 0;

	virtual void castAbility(IAbilitySettings* settings) = 0;

	virtual int getCurrentParticipantIndex() = 0;
};

#endif