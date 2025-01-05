#ifndef BOT_CONTROLLER_H
#define BOT_CONTROLLER_H

#include "ParticipantController.h"

#include "Game.h"
#include "ICommand.h"
#include "Bot.h"

class BotController : public ParticipantController
{
	Coords lastStand = { 0, 0 };

	ICommand* placeShip();

public:

	BotController(Game& game, int index);

	ICommand* getAction() override;
};

#endif