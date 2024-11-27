#include "Participant.h"

#include "ScannerResult.h"
#include "CLIInput.h"

struct Player : public Participant
{
	CLIInput mInput;

	Player(Coords fieldSize, std::vector<std::pair<int, int>> shipList) :
		Participant(fieldSize, shipList) {}

	void placeShips() override;

	class ICommand* getAction() override;
};