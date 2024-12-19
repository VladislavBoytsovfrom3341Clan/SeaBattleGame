#ifndef BOT_CONTROLLER_H
#define BOT_CONTROLLER_H

#include "ParticipantController.h"

#include "Game.h"
#include "ICommand.h"
#include "Bot.h"

class BotController : public ParticipantController
{
	void placeShips();

public:

	BotController(Game& game);

	ICommand* getAction() override;
};

#endif