#include "Participant.h"

struct Bot: public Participant
{
	Bot(Coords fieldSize, std::vector<std::pair<int, int>> shipList) :
		Participant(fieldSize, shipList) {}

	void placeShips() override;

	class ICommand* getAction() override;
};