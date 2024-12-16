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
#include <iostream>

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
		BotController* controller = new BotController();
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
	catch (const NoAbilityException& na)
	{
		std::cout << na.what();
	}
	catch (const OutOfRangeAttackException& ora)
	{
		std::cout << ora.what();
	}
	catch(const ShipPlacementException& sp)
	{
		std::cout << sp.what();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	delete command;
}

void GameController::observeGame()
{
	for (int i = 0; i < mControllers.size(); i++)
		mControllers[i]->observe(mGame.getInfo(), i);
}

void GameController::runRoundCycle()
{
	while (mGame.countAlivePlayers() >= 1 && mGame.countAliveParticipants()>1)
	{
		mGame.newMove();
		this->observeGame();
		ICommand* command = mControllers[mGame.getCurrentParticipantIndex()]->getAction();
		this->acceptCommand(command);
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

//all COUTs is ONLY for DUBUG time
void GameController::runGameCycle()
{
	mGame.newRound();
	std::cout << "Started ship placing phase\n";
	for (int i=0; i<mControllers.size(); i++)
	{
		ParticipantController* controller = mControllers[i];
		while (!(controller->isReady()))
		{
			controller->observe(mGame.getInfo(), i);
			ICommand* command = controller->getAction();
			this->acceptCommand(command);
		}
	}
	std::cout << "Ended ship placing phase\n";
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
