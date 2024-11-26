#include "GameController.h"

#include "Game.h"
#include "ICommand.h"

#include <iostream>

void GameController::runRoundCycle()
{
	while (mGame->countAliveParticipants() > 1)
	{
		Participant* currentParticipant = mGame->getCurrentParticipant();
		ICommand* command = currentParticipant->getAction();
		command->execute(*mGame);
		delete command;
		mGame->Display();
		mGame->newMove();
	}
}

void GameController::runGameCycle()
{
	mGame->generateBots(2);
	while (mGame->countAlivePlayers() > 0)
	{
		std::cout << "\nNew round has started!\n";
		this->runRoundCycle();
		mGame->newRound();
	}
	std::cout << "\nGame ended!\n";
}

void GameController::startGame()
{
	this->runGameCycle();
}
