#ifndef CLI_INPUT_H
#define CLI_INPUT_H

#include "ICommand.h"
#include "Coords.h"

#include <unordered_map>
#include <string>
#include <functional>

class CLIInput
{
	std::unordered_map<char, std::string> mBindedKeys;

	std::unordered_map<std::string, std::function<ICommand*()>> mCommandsParser;

	Coords readCoords(std::string message = "");

	Orientation readOrientation();

	int readIndex(std::string message = "");

	void printBindedKeys();

public:
	CLIInput();

	ICommand* readCommand();

	void rebindKeysFromFile(std::string fileName = "key_binds.txt");
};

#endif