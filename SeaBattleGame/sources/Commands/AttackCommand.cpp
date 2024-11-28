#include "AttackCommand.h"

#include "Game.h"

AttackCommand::AttackCommand(int participantIndex, Coords targetCoords) :
	mAttackedParticipantIndex(participantIndex), mTargetCoords(targetCoords) {}

void AttackCommand::execute(class Game& game)
{
	game.attack(mAttackedParticipantIndex, mTargetCoords);
}
