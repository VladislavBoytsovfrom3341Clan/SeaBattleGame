#include "AttackState.h"

#include "Participant.h"

#include <iostream>

AttackState::AttackState(GameInfo& info) :
	mInfo(info) {}

void AttackState::placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation)
{
}

void AttackState::castAbility(IAbilitySettings* settings)
{
	mInfo.mParticipants.at(mInfo.mMoveIndex % mInfo.mParticipantsNumber)->mAbilityManager.castLastAbility(*settings);
}

void AttackState::attack(int index, Coords coords, int damage)
{
	mInfo.mParticipants.at(index)->mField.attackCell(coords, damage);
	mInfo.mParticipants.at(index % mInfo.mParticipantsNumber)->mDamageMultiplier = 1;
	mInfo.mMoveIndex++;
}


