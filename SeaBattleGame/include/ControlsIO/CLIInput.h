#ifndef CLI_INPUT_H
#define CLI_INPUT_H

#include "ICommand.h"

class CLIInput
{
public:
	CLIInput() = default;

	ICommand* readCommand();
};

#endif