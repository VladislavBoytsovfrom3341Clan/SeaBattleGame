#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "ICommand.h"

#include <unordered_set>

class InputHandler
{
	std::unordered_set<std::string> mCommands;
public:

	InputHandler();

	template<typename Input>
	ICommand* getCommand(Input& input);

	const std::unordered_set<std::string>& getCommandsSet();
};

template<typename Input>
inline ICommand* InputHandler::getCommand(Input& input)
{
	return input.readCommand();

}

#endif


