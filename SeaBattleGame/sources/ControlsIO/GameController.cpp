#include "GameController.h"

#include "GameState.h"

#include <iostream>

void GameController::acceptCommand(ICommand* command) 
{
	command->execute(*this);
	std::cout << "\nController nayebashil\n";
}

void GameController::attackParticipant(int participantIndex, Coords coords)
{
	mGState.attackParticipant(participantIndex, coords);
}