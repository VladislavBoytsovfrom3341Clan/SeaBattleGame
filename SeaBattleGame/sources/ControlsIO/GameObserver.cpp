#include "GameObserver.h"

#include "ScannerResult.h"
#include "ShipPosState.h"
#include "Player.h"

GameObserver::GameObserver(Game& game, IGameDisplayer* displayer):
	mGame(game), mDisplayer(displayer){}

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

void GameObserver::checkNewRound()
{
	if (mGame.getInfo().mMoveIndex == 0)
	{
		if (!mRoundStartChecked)
		{
			mDisplayer->informNewRound();
			mRoundStartChecked = true;
		}
	}
	else
	{
		mRoundStartChecked = false;
		mGameStartChecked = false;
	}
}

void GameObserver::checkNewGame()
{
	if (mGame.getInfo().mRoundCount == 1)
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

void GameObserver::track(int pIndex)
{
	if (mDisplayer != nullptr)
	{
		this->checkNewGame();
		this->checkNewRound();
		if (mGame.getInfo().mMoveIndex == 0 && !mGame.getParticipant(pIndex)->isReady())
		{
			mDisplayer->displayShipPositioning(mGame.getInfo(), pIndex);
		}
		else
		{
			this->checkAbilityResultChanges(mGame.getParticipant(pIndex));
			mDisplayer->display(mGame.getInfo(), pIndex);
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

Coords GameObserver::getFieldSize(int pIndex)
{
	return mGame.getParticipant(pIndex)->mField.size();
}