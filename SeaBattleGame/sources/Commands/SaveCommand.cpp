#include "SaveCommand.h"

#include "Game.h"

//Simply calls Game::save()
//TODO: add custom savefile name
void SaveCommand::execute(Game& game)
{
	game.save();
}
