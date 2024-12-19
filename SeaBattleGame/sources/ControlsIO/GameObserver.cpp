#include "GameObserver.h"

#include "ScannerResult.h"
#include "ShipPosState.h"
#include "Player.h"

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
		Participant* curParticipant = game.getParticipant(pIndex);
		if (curParticipant->mHandler.getResult() != nullptr)
		{
			mDisplayer->displayAbilityResultResult(*curParticipant->mHandler.getResult());
			curParticipant->mHandler.setResult(nullptr);
		}
		if (typeid(game.getState()) == typeid(ShipPosState))
			mDisplayer->displayShipPositioning(game.getInfo(), pIndex);
		else
			mDisplayer->display(game.getInfo(), pIndex);
	}
}
