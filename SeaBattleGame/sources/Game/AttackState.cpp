#include "AttackState.h"

#include "Participant.h"

#include <iostream>

AttackState::AttackState(std::vector<Participant*>& participants, int& moveIndex, int& participantsNumber) :
	mParticipants(participants), mMoveIndex(moveIndex), mParticipantsNumber(participantsNumber) {}

void AttackState::placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation)
{
}

void AttackState::castAbility(IAbilitySettings* settings)
{
	mParticipants[mMoveIndex % mParticipantsNumber]->mAbilityManager.castLastAbility(*settings);
}

void AttackState::attack(int index, Coords coords, int damage)
{
	mParticipants[index]->mField.attackCell(coords, damage);
	mParticipants[index % mParticipantsNumber]->mDamageMultiplier = 1;
	mMoveIndex++;
	//std::cout << "Gribuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu " << mMoveIndex << '\n';
}


