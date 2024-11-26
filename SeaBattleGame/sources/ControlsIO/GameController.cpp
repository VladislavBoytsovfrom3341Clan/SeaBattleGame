#include "GameController.h"

#include "Game.h"

#include <iostream>

void GameController::acceptCommand(ICommand* command) 
{
	command->execute(*this);
	std::cout << "\nController nayebashil\n";
}

void GameController::attackParticipant(int participantIndex, Coords coords)
{
	mGame->attackParticipant(participantIndex, coords);
}