#include "Participant.h"

#include "CLIInput.h"

struct Player : public Participant
{
	CLIInput mInput;

	Player(GameController* controller, Coords fieldSize, std::initializer_list<std::pair<int, int>> shipList) :
		Participant(controller, fieldSize, shipList) {}

	void placeShips() override;

	void act() override;

	class ICommand* getAction() override;
};