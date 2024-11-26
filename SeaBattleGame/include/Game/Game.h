#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "Coords.h"

class Game
{
	std::vector<Participant*> mParticipants;
	GameState* mState;
	int mMoveIndex = 0;
	int mRoundCount = 0;
	int mBotsNumber = 1;
	int mPlayersNumber = 0;
	int mParticipantsNumber = 1;
	Coords mFieldSize = { 5, 5 };
	std::vector<std::pair<int, int>> mDefaultShips{ {1, 1} };

	bool gameRoundCycle();

	void regenerateBots();

public:
	
	Game(Coords fieldSize);

	void addPlayerByController(class GameController& controller);

	void setBotsNumber(int number);

	void shipPositioning();

	void standartGameCycle();

	bool attackParticipant(int index, Coords coords);

//	void addAbilityToParticipant(int index);

//  castAbility???\

	Participant* getCurrentParticipant();

	void createBot(int index);

	void createPlayer(int index);

	void removeParticipant(int index);

	int countAliveParticipants();

	int countAliveBots();

	int countAlivePlayers();



	void Display();
};

#endif