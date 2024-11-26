#ifndef SHIP_POS_STATE_H
#define SHIP_POS_STATE_H

#include "GameState.h"

class ShipPosState : public GameState
{
	std::vector<Participant*>& mParticipants;

public:

	ShipPosState(std::vector<Participant*>& participants);

	void placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation) override;

	void attack(int index, Coords coords) override;
};

#endif