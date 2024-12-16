#ifndef SAVE_COMMAND_H
#define SAVE_COMMAND_H

#include "ICommand.h"

class SaveCommand : public ICommand
{
public:
	SaveCommand() = default;

	void execute(class Game& game) override;
};

#endif