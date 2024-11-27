#ifndef ATTACK_STATE_H
#define ATTACK_STATE_H

#include "GameState.h"

#include "Participant.h"

class AttackState : public GameState
{
	std::vector<Participant*>& mParticipants;
	bool mHasAnAttack = true;

public:

	AttackState(std::vector<Participant*>& participants);

	bool participantMayAct(int index) override;

	void placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation) override;

	void attack(int index, Coords coords) override;
};

#endif