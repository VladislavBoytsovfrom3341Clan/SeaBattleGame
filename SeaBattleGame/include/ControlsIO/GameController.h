#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

//#include "GameState.h"
#include "ICommand.h"
#include "Coords.h"

class GameController
{
	class GameState& mGState;

public:

	GameController(class GameState& gState) : mGState(gState) {}

	void acceptCommand(ICommand* command);

	void attackParticipant(int participantIndex, Coords coords);
};

#endif