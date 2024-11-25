#include "AttackCommand.h"

#include "GameController.h"
#include <iostream>

AttackCommand::AttackCommand(int participantIndex, Coords targetCoords) :
	mAttackedParticipantIndex(participantIndex), mTargetCoords(targetCoords) {}

void AttackCommand::execute(GameController& gameController)
{
	gameController.attackParticipant(mAttackedParticipantIndex, mTargetCoords);
	std::cout << "\nA\n";
}
