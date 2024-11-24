#include "Participant.h"

struct Player : public Participant
{
	Player(Coords fieldSize, std::initializer_list<std::pair<int, int>> shipList) :
		Participant(fieldSize, shipList) {}

	void placeShips() override;

	int getAction() override;
};