#ifndef GAME_H
#define GAME_H

#include "GameSettings.h"
#include "IAbilitySettings.h"
#include "GameState.h"
#include "GameInfo.h"
#include "Participant.h"
#include "Coords.h"
#include "GameSaver.h"
#include "FileHandler.h"

class Game
{
	GameInfo mInfo;
	GameState* mState = nullptr;
	GameSettings& mSettings;
	GameSaver mSaver;
	FileHandler mHandler;

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

	void save();

	void load();

	Participant* getCurrentParticipant();

	Participant* getParticipant(int index);

	int getCurrentParticipantIndex();

	int countAliveParticipants();

	int countAliveBots();

	int countAlivePlayers();

	void Display();
};

#endif