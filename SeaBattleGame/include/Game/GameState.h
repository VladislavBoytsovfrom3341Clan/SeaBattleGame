#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "Coords.h"

#include <vector>

class GameState
{
public:

	virtual bool participantMayAct(int index) = 0;

	virtual void placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation) = 0;

	virtual void attack(int index, Coords coords) = 0;

};

#endif