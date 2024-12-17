#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include "Game.h"
#include "IGameDisplayer.h"

class GameObserver
{
	IGameDisplayer* mDisplayer = nullptr;

public:

	GameObserver(IGameDisplayer* displayer = nullptr);

	void changeDisplayer(IGameDisplayer* displayer);

	void track(Game& game, int pIndex);
};

#endif