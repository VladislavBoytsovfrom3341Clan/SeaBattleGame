#ifndef SAVE_COMMAND_H
#define SAVE_COMMAND_H

#include "ICommand.h"


/*
* Command orders to save current game state
*/
class SaveCommand : public ICommand
{
public:
	SaveCommand() = default;

	//Saves game
	void execute(class Game& game) override;
};

#endif