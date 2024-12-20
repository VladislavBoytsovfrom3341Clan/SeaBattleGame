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

	bool mNeedSync = false;

public:
	
	Game(GameSettings& settings);

	//methods for setting up participants 

	void addParticipant(Participant* participant);

	Participant* resetPlayer(int index);

	Participant* resetBot(int index);

	bool checkSync();

	void synchronize();

	//methods for updating moves and states

	void newMove();

	void newRound();

	void newGame();

	//methods used to perform actions

	void placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation);

	void attack(int index, Coords coords);

	void castAbility(IAbilitySettings* settings);

	void save();

	void load();

	//getters for extern classes to manipulate the game

	const GameInfo& getInfo();

	Participant* getCurrentParticipant() const;

	Participant* getParticipant(int index) const;

	int getCurrentParticipantIndex() const;

	//methods for game end control

	int countAliveParticipants() const;

	int countAliveBots() const;

	int countAlivePlayers() const;

	~Game();
};

#endif