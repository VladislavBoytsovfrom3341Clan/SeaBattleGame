#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "ParticipantController.h"

#include "Player.h"
#include "CLIInput.h"

class PlayerController : public ParticipantController
{
	CLIInput mInput;

public:

	PlayerController() = default;

	ICommand* getAction() override;
};

#endif