#include "GameController.h"

#include "Participant.h"
#include "Player.h"
#include "Bot.h"
#include "PlayerController.h"
#include "BotController.h"
#include "Game.h"
#include "ICommand.h"
#include "GameSettings.h"

#include <iostream>

GameController::GameController(Game& game, GameSettings& settings) :
	mGame(game), mSettings(settings) {}

void GameController::addPlayerController(PlayerController& controller)
{
	Player* newPlayer = new Player(mSettings.mFieldSize, mSettings.mDefaultShips);
	controller.setParticipant(newPlayer);
	mControllers.push_back(&controller);
	mGame.addParticipant(newPlayer);
}

void GameController::addBots(int number)
{
	for (int i = 0; i < number; i++)
	{
		Bot* newBot = new Bot(mSettings.mFieldSize, mSettings.mDefaultShips);
		BotController* controller = new BotController();
		controller->setParticipant(newBot);
		mControllers.push_back(controller);
		mGame.addParticipant(newBot);
	}
}

void GameController::runRoundCycle()
{
	while (mGame.countAlivePlayers() >= 1 && mGame.countAliveParticipants()>1)
	{
		mGame.newMove();
		mGame.Display();
		ICommand* command = mControllers[mGame.getCurrentParticipantIndex()]->getAction();
		command->execute(mGame);
		delete command;
	}
}

void GameController::resetBots()
{
	for (int i = 0; i < mControllers.size(); i++)
	{
		if (typeid(*(mControllers[i])) == typeid(BotController))
		{
			mControllers[i]->setParticipant(mGame.resetBot(i));
		}
		while (!(mControllers[i]->isReady()))
		{
			ICommand* command = mControllers[i]->getAction();
			command->execute(mGame);
			delete command;
		}
	}
}

void GameController::runGameCycle()
{
	mGame.newRound();
	for (ParticipantController* controller : mControllers)
	{
		while (!(controller->isReady()))
		{
			ICommand* command = controller->getAction();
			command->execute(mGame);
			delete command;
		}
	}
	std::cout << "Ended ship placing phase\n";
	mGame.Display();
	while (mGame.countAlivePlayers() > 0)
	{
		std::cout << "\nNew round has started!\n";
		this->runRoundCycle();
		mGame.newRound();
		this->resetBots();
	}
	std::cout << "\nGame ended!\n";
}

void GameController::startGame()
{
	this->runGameCycle();
}
