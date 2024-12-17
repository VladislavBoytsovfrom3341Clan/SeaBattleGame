#include "CLIInput.h"

#include "AttackCommand.h"
#include "PlaceShipCommand.h"
#include "DoubleDamageCommand.h"
#include "ShellingCommand.h"
#include "ScannerCommand.h"
#include "SaveCommand.h"
#include "LoadCommand.h"

#include <exception>
#include <iostream>

CLIInput::CLIInput()
{
	mBindedKeys =
	{
		{'f', "AttackCommand"},
		{'q', "DoubleDamageCommand" },
		{'l', "LoadCommand"},
		{'r', "PlaceShipCommand"},
		{'s', "SaveCommand"},
		{'e', "ScannerCommand"},
		{'w', "ShellingCommand"}
	};

	mCommandsParser =
	{
		{"AttackCommand", [&]() {return new AttackCommand(readIndex("target player"), readCoords()); }},
		{"DoubleDamageCommand", [&]() {return new DoubleDamageCommand(); }},
		{"LoadCommand", [&]() {return new LoadCommand(); }},
		{"PlaceShipCommand", [&]() {return new PlaceShipCommand(0, readIndex("ship"), readCoords(), readOrientation()); }},
		{"SaveCommand", [&]() {return new SaveCommand(); }},
		{"ScannerCommand", [&]() {return new ScannerCommand(readIndex("target player"), readCoords()); }},
		{"ShellingCommand", [&]() {return new ShellingCommand(readIndex("target player")); }}
	};
}

ICommand* CLIInput::readCommand()
{
	ICommand* newCommand = nullptr;
	std::string readCommand = "";
	auto readKey = mBindedKeys.begin();
	do
	{
		std::cout << "\nEnter Command:\n";
		char key;
		if (std::cin >> key)
		{
			readKey = mBindedKeys.find(key);
			if (readKey == mBindedKeys.end())
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\nUnknown command\n";
			}
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nUnknown command\n";
		}
	} 
	while (readKey == mBindedKeys.end());
	readCommand = readKey->second;
	int playerIndex = 0;
	try
	{
		newCommand = mCommandsParser[readCommand]();
	}
	catch (std::exception& e)
	{
		newCommand = nullptr;
		std::cout << "\ncathed da shit\n";
	}
	return newCommand;
}

Coords CLIInput::readCoords(std::string message)
{
	std::cout << "\nEnter "<<message<<" coordinates: <x y>\n";
	int x, y;
	while (true)
	{
		if(std::cin >> x >> y)
			return { x, y };
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nCoordinates reading error. Try again in format: <x y>\n";
		}
	}
	
}

Orientation CLIInput::readOrientation()
{
	std::cout << "\nEnter ship orientation: <v> for vertical and <h> for horizontal\n";
	char c;
	while (true)
	{
		if (std::cin >> c && (c == 'v' || c == 'h'))
		{
			if (c == 'v')
				return Orientation::vertical;
			else return Orientation::horizontal;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nShip orientation reading error. Try again in format <v> or <h>\n";
		}
	}
}

int CLIInput::readIndex(std::string message)
{
	std::cout << "\nEnter " << message << " index: <i>\n";
	int index;
	while (true)
	{
		if(std::cin >> index)
			return index;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nIndex reading error. Try again in format <i>\n";
		}
	}
	
}