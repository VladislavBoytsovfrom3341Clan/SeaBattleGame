#include "AttackState.h"

#include "Participant.h"

AttackState::AttackState(std::vector<Participant*>& participants) :
	mParticipants(participants) {}

bool AttackState::participantMayAct(int index)
{
	return mHasAnAttack;
}

void AttackState::placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation)
{
}

void AttackState::attack(int index, Coords coords)
{
	mParticipants[index]->mField.attackCell(coords);
	mHasAnAttack = false;
}


