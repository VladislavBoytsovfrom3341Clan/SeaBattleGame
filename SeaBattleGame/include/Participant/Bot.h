#include "Participant.h"

struct Bot: public Participant
{
	Bot(Coords fieldSize, std::initializer_list<std::pair<int, int>> shipList) :
		Participant(fieldSize, shipList) {
	}

	void placeShips() override;

	int getAction() override;
};