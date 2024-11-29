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
	if(mInfo.mUsedAbility == false)
		mInfo.mParticipants.at(mInfo.mMoveIndex % mInfo.mParticipantsNumber)->mAbilityManager.castLastAbility(*settings);
	mInfo.mUsedAbility = true;
}

void AttackState::attack(int index, Coords coords, int damage)
{
	bool destroyed = mInfo.mParticipants.at(index)->mField.attackCell(coords, damage);
	mInfo.mParticipants.at(mInfo.mMoveIndex % mInfo.mParticipantsNumber)->mDamageMultiplier = 1;
	if (destroyed)
		mInfo.mParticipants.at(mInfo.mMoveIndex % mInfo.mParticipantsNumber)->mAbilityManager.addRandomAbility();
	mInfo.mMoveIndex++;
	mInfo.mUsedAbility = false;
}


