#include "SaveCommand.h"

#include "Game.h"

#include <iostream>

void SaveCommand::execute(Game& game)
{
	std::cout << "+Command\n";
	game.save();
}
