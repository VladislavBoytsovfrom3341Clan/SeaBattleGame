#include "Participant.h"

struct Bot: public Participant
{
	Bot(GameController* controller, Coords fieldSize, std::vector<std::pair<int, int>> shipList) :
		Participant(controller, fieldSize, shipList) {
	}

	void placeShips() override;

	void act() override;

	class ICommand* getAction() override;
};