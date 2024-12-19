#include "SaveCommand.h"

#include "Game.h"


void SaveCommand::execute(Game& game)
{
	game.save();
}
