#ifndef ATTACK_COMMAND_H
#define ATTACK_COMMAND_H

#include "ICommand.h"
#include "Battlefield.h"

class AttackCommand : public ICommand
{
	int mAttackedParticipantIndex;
	Coords mTargetCoords;

public:
	AttackCommand(int participantIndex, Coords targetCoords);

	void execute(class GameState& gState) override;
};

#endif