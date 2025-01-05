#ifndef BOT_H
#define BOT_H

#include "Participant.h"

struct Bot: public Participant
{
	Bot(Battlefield field, std::vector<std::shared_ptr<Battleship>> inactive, std::vector<std::shared_ptr<Battleship>> active);

	Bot(Coords fieldSize, std::vector<std::pair<int, int>> shipList);
};

#endif