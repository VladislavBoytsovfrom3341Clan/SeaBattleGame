#include "AttackCommand.h"

#include <iostream>

AttackCommand::AttackCommand(int participantIndex, Coords targetCoords) :
	mAttackedParticipantIndex(participantIndex), mTargetCoords(targetCoords) {}

void AttackCommand::execute(GameState& gState)
{
	gState.attackParticipant(mAttackedParticipantIndex, mTargetCoords);
	std::cout << "\nA\n";
}
