#ifndef ATTACK_STATE_H
#define ATTACK_STATE_H

#include "GameState.h"

class AttackState : public GameState
{
	std::vector<Participant*>& mParticipants;

public:

	AttackState(std::vector<Participant*>& participants);

	void placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation) override;

	void attack(int index, Coords coords) override;
};

#endif