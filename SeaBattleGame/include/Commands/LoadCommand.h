#ifndef LOAD_COMMAND_H
#define LOAD_COMMAND_H

#include "ICommand.h"


/*
* Command orders to load game from savefile
*/
class LoadCommand : public ICommand
{
	//TODO: add path to savefile to make multiple loads
public:
	LoadCommand() = default;

	//orders game to load
	void execute(class Game& game) override;
};

#endif