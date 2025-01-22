#include "AttackCommand.h"

#include "Game.h"

AttackCommand::AttackCommand(int participantIndex, Coords targetCoords) :
	mAttackedParticipantIndex(participantIndex), mTargetCoords(targetCoords) {}

//Simply calls game::attack() method 
void AttackCommand::execute(class Game& game)
{
	game.attack(mAttackedParticipantIndex, mTargetCoords);
}
