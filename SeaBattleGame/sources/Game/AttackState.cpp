#include "AttackState.h"

AttackState::AttackState(std::vector<Participant*>& participants) :
	mParticipants(participants) {}

void AttackState::placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation)
{
}

void AttackState::attack(int index, Coords coords)
{
	mParticipants[index]->mField.attackCell(coords);
}


