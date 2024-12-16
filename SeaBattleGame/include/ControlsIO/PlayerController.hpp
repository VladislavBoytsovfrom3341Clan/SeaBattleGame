#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "ParticipantController.h"

#include "Player.h"
#include "CLIInput.h"

template <typename Input>
class PlayerController : public ParticipantController
{
	Input mInput;

public:

	PlayerController() = default;

	ICommand* getAction() override
	{
		return mInput.readCommand();
	}
};

#endif