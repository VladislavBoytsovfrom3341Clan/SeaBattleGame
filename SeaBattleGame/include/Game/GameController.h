#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Coords.h"
#include "ParticipantController.h"
#include "GameSettings.h"
#include "ICommand.h"

#include <vector>

class GameController
{
	class Game& mGame;

	GameSettings mSettings;

	std::vector<ParticipantController*> mControllers;

	void acceptCommand(ICommand* command);

	void observeGame();

	void resetBots();

	void resetParticipants();

	void runRoundCycle();

	void runGameCycle();

public:

	GameController(class Game& game, GameSettings& settings);
	
	void addPlayerController(ParticipantController& controller);

	void addBots(int number);

	void startGame();
};

#endif