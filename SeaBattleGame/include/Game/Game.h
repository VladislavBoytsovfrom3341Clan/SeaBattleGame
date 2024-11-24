#ifndef GAME_H
#define GAME_H

#include "GameState.h"

class Game
{
	GameState* mState;
	int mMoveIndex = 0;
	int mRoundCount = 0;

	bool gameRoundCycle();

public:
	
	Game(int playersNumber, int botsNumber);

	void shipPositioning();

	void standartGameCycle();
};

#endif