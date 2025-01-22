#ifndef CAST_SHELLING_COMMAND_H
#define CAST_SHELLING_COMMAND_H

#include "ICommand.h"


/*
* Orders game to cast Shelling ability
* to some participant
*/
class ShellingCommand : public ICommand
{
	//Index of player on whop Shelling will be casted
	int mPlayerIndex;

public:

	ShellingCommand(int playerIndex);

	//Orders game to cast Shelling
	void execute(class Game& game) override;
};

#endif