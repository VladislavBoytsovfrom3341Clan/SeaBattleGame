#ifndef LOAD_COMMAND_H
#define LOAD_COMMAND_H

#include "ICommand.h"

class LoadCommand : public ICommand
{
public:
	LoadCommand() = default;

	void execute(class Game& game) override;
};

#endif