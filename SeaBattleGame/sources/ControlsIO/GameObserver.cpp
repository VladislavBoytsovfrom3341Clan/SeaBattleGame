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

void GameObserver::checkAbilityResultChanges(Participant* participant)
{
	if (participant->mHandler.getResult() != nullptr)
	{
		mDisplayer->displayAbilityResult(*participant->mHandler.getResult());
		participant->mHandler.setResult(nullptr);
	}
}

void GameObserver::checkNewRound(Game& game)
{
	if (game.getInfo().mMoveIndex == 0)
	{
		if (!mRoundStartChecked)
		{
			mDisplayer->informNewRound();
			mRoundStartChecked = true;
		}
	}
	else
		mRoundStartChecked = false;
}

void GameObserver::checkNewGame(Game& game)
{
	if (game.getInfo().mRoundCount == 1)
	{
		if (!mGameStartChecked)
		{
			mDisplayer->informNewGame();
			mGameStartChecked = true;
			mRoundStartChecked = true;
		}
	}
	else
		mGameStartChecked = false;
}

void GameObserver::track(Game& game, int pIndex)
{
	if (mDisplayer != nullptr)
	{
		this->checkNewGame(game);
		this->checkNewRound(game);
		if (typeid(game.getState()) == typeid(ShipPosState))
		{
			mDisplayer->displayShipPositioning(game.getInfo(), pIndex);
		}
		else
		{
			this->checkAbilityResultChanges(game.getParticipant(pIndex));
			mDisplayer->display(game.getInfo(), pIndex);
		}
	}
}

void GameObserver::handleException(std::exception& exp)
{
	if (mDisplayer != nullptr)
	{
		mDisplayer->informError(exp);
	}
}