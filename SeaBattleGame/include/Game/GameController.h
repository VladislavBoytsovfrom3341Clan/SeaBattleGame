#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Coords.h"
#include "ParticipantController.h"
#include "PlayerController.h"
#include "GameSettings.h"

#include <vector>

class GameController
{
	class Game& mGame;

	GameSettings mSettings;

	std::vector<ParticipantController*> mControllers;

public:

	GameController(class Game& game, GameSettings& settings);

	void addPlayerController(PlayerController& controller);

	void addBots(int number);

	void resetBots();

	void runRoundCycle();

	void runGameCycle();

	void startGame();
};

#endif