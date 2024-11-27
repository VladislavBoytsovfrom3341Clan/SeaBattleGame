#ifndef CAST_DOUBLE_DAMAGE_COMMAND_H
#define CAST_DOUBLE_DAMAGE_COMMAND_H

#include "ICommand.h"

class DoubleDamageCommand : public ICommand
{
public:
	DoubleDamageCommand() = default;

	void execute(class Game& game) override;
};

#endif