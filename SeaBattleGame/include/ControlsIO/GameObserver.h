#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include "GameInfo.h"
#include "IGameDisplayer.h"

class GameObserver
{
	IGameDisplayer* mDisplayer = nullptr;

public:

	GameObserver(IGameDisplayer* displayer = nullptr);

	void changeDisplayer(IGameDisplayer* displayer);

	void track(GameInfo& gInfo, int pIndex);
};

#endif