#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

//#include "GameState.h"
#include "ICommand.h"
#include "Coords.h"

class GameController
{
	class Game* mGame;

public:

	GameController(class Game* game) : mGame(game) {}

	void acceptCommand(ICommand* command);

	void attackParticipant(int participantIndex, Coords coords);
};

#endif