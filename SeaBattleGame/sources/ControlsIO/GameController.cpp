#include "GameController.h"

#include "Participant.h"
#include "Game.h"
#include "ICommand.h"

#include <iostream>

void GameController::runRoundCycle()
{
	while (mGame.countAlivePlayers() >= 1 && mGame.countAliveParticipants()>1)
	{
		Participant* currentParticipant = mGame.getCurrentParticipant();
		ICommand* command = currentParticipant->getAction();
		command->execute(mGame);
		delete command;
		mGame.Display();
		mGame.newMove();
	}
}

void GameController::runGameCycle()
{
	while (mGame.participantMayAct())
	{
		ICommand* command = mGame.getCurrentParticipant()->getAction();
		command->execute(mGame);
	}
	while (mGame.countAlivePlayers() > 0)
	{
		mGame.newRound();
		std::cout << "\nNew round has started!\n";
		this->runRoundCycle();
	}
	std::cout << "\nGame ended!\n";
}

void GameController::startGame()
{
	this->runGameCycle();
}
