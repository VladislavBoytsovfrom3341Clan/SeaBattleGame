#ifndef BOT_H
#define BOT_H

#include "Participant.h"

struct Bot: public Participant
{
	Bot(Coords fieldSize, std::vector<std::pair<int, int>> shipList);
};

#endif