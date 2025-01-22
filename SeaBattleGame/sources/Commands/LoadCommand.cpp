#include "LoadCommand.h"

//Simply calls Game::load() method
//TODO: add path
void LoadCommand::execute(Game& game)
{
	game.load();
}
