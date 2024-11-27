#ifndef SHIP_POS_STATE_H
#define SHIP_POS_STATE_H

#include "GameState.h"

#include "Participant.h"

class ShipPosState : public GameState
{
	std::vector<Participant*>& mParticipants;
	int& mMoveIndex;
	int& mParticipantsNumber;

public:

	ShipPosState(std::vector<Participant*>& participants, int& moveIndex, int& participantsNumber);

	void placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation) override;

	void castAbility(IAbilitySettings* settings) override;

	void attack(int index, Coords coords, int damage) override;
};

#endif