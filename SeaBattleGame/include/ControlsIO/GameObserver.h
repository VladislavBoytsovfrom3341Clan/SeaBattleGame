#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include "Game.h"
#include "IGameDisplayer.h"
#include "Coords.h"

#include <stdexcept>

class GameObserver
{
	Game& mGame;
	IGameDisplayer* mDisplayer = nullptr;
	bool mGameStartChecked = false;
	bool mRoundStartChecked = false;

	void checkAbilityResultChanges(Participant* participant);

	void checkNewRound();

	void checkNewGame();

public:

	GameObserver(Game& game, IGameDisplayer* displayer = nullptr);

	void changeDisplayer(IGameDisplayer* displayer);

	void track(int pIndex);

	void handleException(std::exception& exp);

	Coords getFieldSize(int pIndex);
};

#endif