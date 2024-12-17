#include "GameObserver.h"

#include "ShipPosState.h"

GameObserver::GameObserver(IGameDisplayer* displayer):
	mDisplayer(displayer){}

void GameObserver::changeDisplayer(IGameDisplayer* displayer)
{
	mDisplayer = displayer;
}

void GameObserver::track(Game& game, int pIndex)
{
	if (mDisplayer != nullptr)
	{
		if (typeid(game.getState()) == typeid(ShipPosState))
			mDisplayer->displayShipPositioning(game.getInfo(), pIndex);
		else
			mDisplayer->display(game.getInfo(), pIndex);
	}
}

