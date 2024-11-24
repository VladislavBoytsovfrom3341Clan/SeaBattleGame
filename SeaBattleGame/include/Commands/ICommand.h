#ifndef I_COMMAND_H
#define I_COMMAND_H

#include "GameState.h"

class ICommand
{
public:
	virtual void execute(class GameState& gState) = 0;
};

#endif