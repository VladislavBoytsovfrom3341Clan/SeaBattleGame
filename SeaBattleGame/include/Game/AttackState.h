#ifndef ATTACK_STATE_H
#define ATTACK_STATE_H

#include "GameState.h"

#include "Participant.h"

class AttackState : public GameState
{
	std::vector<Participant*>& mParticipants;
	int& mMoveIndex;
	int& mParticipantsNumber;
	bool usedAbility = false;

public:

	AttackState(std::vector<Participant*>& participants, int& moveIndex, int& participantsNumber);

	void placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation) override;

	void castAbility(IAbilitySettings* settings) override;

	void attack(int index, Coords coords, int damage) override;
};

#endif