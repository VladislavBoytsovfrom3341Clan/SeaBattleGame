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
	mParticipants.at(mMoveIndex % mParticipantsNumber)->mAbilityManager.castLastAbility(*settings);
}

void AttackState::attack(int index, Coords coords, int damage)
{
	mParticipants.at(index)->mField.attackCell(coords, damage);
	mParticipants.at(index % mParticipantsNumber)->mDamageMultiplier = 1;
	mMoveIndex++;
}


