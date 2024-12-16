#include "GameObserver.h"

GameObserver::GameObserver(IGameDisplayer* displayer):
	mDisplayer(displayer){}

void GameObserver::changeDisplayer(IGameDisplayer* displayer)
{
	mDisplayer = displayer;
}

void GameObserver::track(GameInfo& gInfo, int pIndex)
{
	if (mDisplayer != nullptr)
		mDisplayer->display(gInfo, pIndex);
}

