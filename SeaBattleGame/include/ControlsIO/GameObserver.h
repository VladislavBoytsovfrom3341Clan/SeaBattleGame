#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include "Game.h"
#include "IGameDisplayer.h"

#include <stdexcept>

class GameObserver
{
	IGameDisplayer* mDisplayer = nullptr;
	bool mGameStartChecked = false;
	bool mRoundStartChecked = false;

	void checkAbilityResultChanges(Participant* participant);

	void checkNewRound(Game& game);

	void checkNewGame(Game& game);

public:

	GameObserver(IGameDisplayer* displayer = nullptr);

	void changeDisplayer(IGameDisplayer* displayer);

	void track(Game& game, int pIndex);

	void handleException(std::exception& exp);
};

#endif