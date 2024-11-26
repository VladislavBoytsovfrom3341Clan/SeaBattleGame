#include "CLIInput.h"

#include "AttackCommand.h"

#include <iostream>

ICommand* CLIInput::readCommand()
{
	int index, x, y;
	std::cout << "\n Enter Command:\n";
	std::cin >> index >> x >> y;
	Coords coords(x, y);
	ICommand* newCommand = new AttackCommand(index, coords);
	return newCommand;
} 