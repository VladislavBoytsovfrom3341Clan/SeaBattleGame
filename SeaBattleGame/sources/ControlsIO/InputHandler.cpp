#include "InputHandler.hpp"

InputHandler::InputHandler()
{
	mCommands = 
	{
		"AttackCommand",
		"DoubleDamageCommand",
		"LoadCommand",
		"PlaceShipCommand",
		"SaveCommand",
		"ScannerCommand",
		"ShellingCommand"
	};
}

const std::unordered_set<std::string>& InputHandler::getCommandsSet()
{
	return mCommands;
}
