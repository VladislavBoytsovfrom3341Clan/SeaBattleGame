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

	GameInfo& getInfo();

	GameState& getState();

	Participant* getCurrentParticipant();

	Participant* getParticipant(int index);

	int getCurrentParticipantIndex();

	int countAliveParticipants();

	int countAliveBots();

	int countAlivePlayers();
};

#endif