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
		mInfo.mParticipants.at(mInfo.mMoveIndex % mInfo.mParticipantsNumber)->mAbilityManager.castFirstAbility(*settings);
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

int AttackState::getCurrentParticipantIndex() const
{
	int endIndex = mInfo.mMoveIndex + mInfo.mParticipantsNumber;
	Participant* currentParticipant = mInfo.mParticipants[mInfo.mMoveIndex % mInfo.mParticipantsNumber].get();
	while (!(currentParticipant->isAlive()) && mInfo.mMoveIndex < endIndex)
		currentParticipant = mInfo.mParticipants[(++mInfo.mMoveIndex) % mInfo.mParticipantsNumber].get();
	if (endIndex == mInfo.mMoveIndex)
		throw std::logic_error("No Alive Participants");
	return mInfo.mMoveIndex % mInfo.mParticipantsNumber;
}


