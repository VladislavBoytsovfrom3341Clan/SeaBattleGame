#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "Participant.h"
#include "Battlefield.h"

#include <vector>

struct Participant;

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

	void attackParticipant(int index, Coords coords);

	void Display(int moveIndex);
};

#endif