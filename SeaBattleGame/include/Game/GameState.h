#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "Player.h"
#include "Bot.h"

#include <vector>

class GameState
{
	std::vector<Participant*> mParticipants;
	Coords mFieldSize = { 5, 5 };

public:

	GameState(int PlayersNumber, int BotsNumber);

	Coords getFieldSize();

	Participant* getCurrentParticipant(int moveIndex);

	Participant* getParticipant(int index);

	void createBot(int index);

	void createPlayer(int index);

	int getParticipantsNumber();

	int countAliveParticipants();

	int countAliveBots();

	int countAlivePlayers();

	void attackParticipant(int index, int x, int y);

	void Display(int moveIndex);
};

#endif