#ifndef GAME_H
#define GAME_H

#include "GameSettings.h"
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
	GameSettings& mSettings;

public:
	
	Game(GameSettings& settings);

	void addParticipant(Participant* participant);

	Participant* resetPlayer(int index);

	Participant* resetBot(int index);

	void newMove();

	void newRound();

	void placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation);

	void attack(int index, Coords coords);

	void castAbility(IAbilitySettings* settings);

//	void addAbilityToParticipant(int index);

//  castAbility???\

	Participant* getCurrentParticipant();

	Participant* getParticipant(int index);

	int getCurrentParticipantIndex();

	int countAliveParticipants();

	int countAliveBots();

	int countAlivePlayers();

	void Display();
};

#endif