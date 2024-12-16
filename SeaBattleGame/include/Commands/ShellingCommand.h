#ifndef CAST_SHELLING_COMMAND_H
#define CAST_SHELLING_COMMAND_H

#include "ICommand.h"

class ShellingCommand : public ICommand
{
	int mPlayerIndex;

public:

	ShellingCommand(int playerIndex);

	void execute(class Game& game) override;
};

#endif