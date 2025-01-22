#ifndef I_COMMAND_H
#define I_COMMAND_H

#include "Game.h"

/*
* Interface describing behavior of any command
* that may be received from Controllers
*/
class ICommand
{
public:

	//Basically should call some Game methods
	virtual void execute(Game& game) = 0;
};

#endif