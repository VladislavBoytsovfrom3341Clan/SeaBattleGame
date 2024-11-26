#include "AttackCommand.h"

#include "Game.h"
#include <iostream>

AttackCommand::AttackCommand(int participantIndex, Coords targetCoords) :
	mAttackedParticipantIndex(participantIndex), mTargetCoords(targetCoords) {}

void AttackCommand::execute(class Game& game)
{
	game.attackParticipant(mAttackedParticipantIndex, mTargetCoords);
	std::cout << "\nAttacked\n";
}
