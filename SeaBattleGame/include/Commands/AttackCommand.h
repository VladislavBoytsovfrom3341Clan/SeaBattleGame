#ifndef ATTACK_COMMAND_H
#define ATTACK_COMMAND_H

#include "ICommand.h"
#include "Coords.h"


/*
* Command orders to attack some player's field at some coords
*/
class AttackCommand : public ICommand
{
	int mAttackedParticipantIndex;
	Coords mTargetCoords;

public:
	AttackCommand(int participantIndex, Coords targetCoords);

	//Attacks player set by index at set coords
	void execute(class Game& game) override;
};

#endif