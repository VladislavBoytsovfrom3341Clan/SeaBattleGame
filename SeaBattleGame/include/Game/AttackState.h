#ifndef ATTACK_STATE_H
#define ATTACK_STATE_H

#include "GameState.h"

#include "GameInfo.h"
#include "Participant.h"

class AttackState : public GameState
{
	GameInfo& mInfo;

public:

	AttackState(GameInfo& info);

	void placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation) override;

	void castAbility(IAbilitySettings* settings) override;

	void attack(int index, Coords coords, int damage) override;

	int getCurrentParticipantIndex() override;
};

#endif