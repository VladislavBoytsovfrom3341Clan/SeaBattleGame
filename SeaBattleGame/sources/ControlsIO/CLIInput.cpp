#include "CLIInput.h"

#include "Coords.h"
#include "AttackCommand.h"
#include "PlaceShipCommand.h"
#include "DoubleDamageCommand.h"
#include "ShellingCommand.h"
#include "ScannerCommand.h"

#include <iostream>

ICommand* CLIInput::readCommand()
{
	std::cout << "\n Enter Command:\n";
	ICommand* newCommand = nullptr;
	char key;
	int playerIndex = 0;
	std::cin >> key;
	switch (key)
	{
	case 'f':
	{
		Coords coords;
		int index;
		std::cin >> index >> coords.x >> coords.y;
		newCommand = new AttackCommand(index, coords);
		break;
	}
	case 'r':
	{
		int shipIndex;
		Coords coords;
		std::cin >> shipIndex >> coords.x >> coords.y;
		Orientation orientation = Orientation::vertical;
		char ornt;
		std::cin >> ornt;
		if (ornt == 'v')
			orientation = Orientation::vertical;
		else if (ornt == 'h')
			orientation = Orientation::horizontal;
		newCommand = new PlaceShipCommand(playerIndex, shipIndex, coords, orientation);
		break;
	}
	case 'q':
	{
		newCommand = new DoubleDamageCommand();
		break;
	}
	case 'w':
	{
		int index;
		std::cin >> index;
		newCommand = new ShellingCommand(index);
		break;
	}
	case 'e':
	{
		int index;
		Coords coords;
		std::cin >> index >> coords.x >> coords.y;
		newCommand = new ScannerCommand(index, coords);
	}
	default:
		break;
	}
	return newCommand;
}