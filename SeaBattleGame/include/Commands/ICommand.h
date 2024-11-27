#ifndef I_COMMAND_H
#define I_COMMAND_H

#include "Game.h"

class ICommand
{
public:
	virtual void execute(Game& game) = 0;
};

#endif