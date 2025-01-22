#ifndef CAST_DOUBLE_DAMAGE_COMMAND_H
#define CAST_DOUBLE_DAMAGE_COMMAND_H

#include "ICommand.h"


/*
* Command orders to execute DoubleDamage ability
* setting multiplier of CURRENT participant
*/
class DoubleDamageCommand : public ICommand
{
public:
	DoubleDamageCommand() = default;

	//Sets current Participant multiplier to 2
	void execute(class Game& game) override;
};

#endif