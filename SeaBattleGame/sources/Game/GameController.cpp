#include "GameController.h"

#include "Participant.h"
#include "Player.h"
#include "Bot.h"
#include "PlayerController.hpp"
#include "BotController.h"
#include "Game.h"
#include "ICommand.h"
#include "GameSettings.h"
#include "NoAbilityException.h"
#include "OutOfRangeAttackException.h"
#include "ShipPlacementException.h"

#include <exception>
#include <stdexcept>

GameController::GameController(Game& game, GameSettings& settings) :
	mGame(game), mSettings(settings) {}

void GameController::addPlayerController(ParticipantController& controller)
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
		BotController* controller = new BotController(mGame);
		controller->setParticipant(newBot);
		mControllers.push_back(controller);
		mGame.addParticipant(newBot);
	}
}

void GameController::acceptCommand(ICommand* command)
{
	try
	{
		if (command != nullptr)
			command->execute(mGame);
	}
	catch (std::exception& e)
	{
		mControllers[mGame.getCurrentParticipantIndex()]->handleException(e);
	}
	delete command;
}

void GameController::observeGame()
{
	for (int i = 0; i < mControllers.size(); i++)
		mControllers[i]->observe(mGame, i);
}

void GameController::runRoundCycle()
{
	while (mGame.countAlivePlayers() >= 1 && mGame.countAliveParticipants()>1)
	{
		mGame.newMove();
		this->observeGame();
		ICommand* command = mControllers[mGame.getCurrentParticipantIndex()]->getAction();
		this->acceptCommand(command);
		this->observeGame();
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
			this->acceptCommand(command);
		}
	}
}

void GameController::resetParticipants()
{
	for (int i = 0; i < mControllers.size(); i++)
	{
		if (typeid(*(mControllers[i])) == typeid(BotController))
		{
			mControllers[i]->setParticipant(mGame.resetBot(i));
		}
		else
		{
			mControllers[i]->setParticipant(mGame.resetPlayer(i));
		}
		while (!(mControllers[i]->isReady()))
		{
			mControllers[i]->observe(mGame, i);
			ICommand* command = mControllers[i]->getAction();
			this->acceptCommand(command);
		}
	}
}

void GameController::runGameCycle()
{
	mGame.newRound();
	for (int i=0; i<mControllers.size(); i++)
	{
		ParticipantController* controller = mControllers[i];
		while (!(controller->isReady()))
		{
			controller->observe(mGame, i);
			ICommand* command = controller->getAction();
			this->acceptCommand(command);
		}
	}
	while (mGame.countAlivePlayers() > 0)
	{
		this->runRoundCycle();
		mGame.newRound();
		this->resetBots();
	}
}

void GameController::startGame()
{
	while (true)
	{
		this->runGameCycle();
		mGame.newGame();
		this->resetParticipants();
	}
}
