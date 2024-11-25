#ifndef ATTACK_COMMAND_H
#define ATTACK_COMMAND_H

#include "ICommand.h"
#include "Coords.h"

class AttackCommand : public ICommand
{
	int mAttackedParticipantIndex;
	Coords mTargetCoords;

public:
	AttackCommand(int participantIndex, Coords targetCoords);

	void execute(class GameController& gameController) override;
};

#endif