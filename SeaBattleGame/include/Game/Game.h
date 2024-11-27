#ifndef GAME_H
#define GAME_H

#include "IAbilitySettings.h"
#include "GameState.h"
#include "Participant.h"
#include "Coords.h"

class Game
{
	std::vector<Participant*> mParticipants;
	GameState* mState = nullptr;
	int mMoveIndex = 0;
	int mRoundCount = 0;
	int mBotsNumber = 0;
	int mPlayersNumber = 0;
	int mParticipantsNumber = 0;
	Coords mFieldSize = { 5, 5 };
	std::vector<std::pair<int, int>> mDefaultShips{ {1, 1} };

	bool gameRoundCycle();

public:
	
	Game(Coords fieldSize, int botsNumber);

	void generateBots(int number);

	void regenerateBots();

	void newMove();

	void newRound();

	bool participantMayAct();

	void placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation);

	void attack(int index, Coords coords);

	void castAbility(IAbilitySettings* settings);

//	void addAbilityToParticipant(int index);

//  castAbility???\

	Participant* getParticipant(int index);

	Participant* getCurrentParticipant();

	int countAliveParticipants();

	int countAliveBots();

	int countAlivePlayers();

	void Display();
};

#endif