#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

//#include "GameState.h"
#include "ICommand.h"
#include "Coords.h"

class GameController
{
	class Game& mGame;

public:

	GameController(class Game& game) : mGame(game) {}

	void runRoundCycle();

	void runGameCycle();

	void startGame();
};

#endif