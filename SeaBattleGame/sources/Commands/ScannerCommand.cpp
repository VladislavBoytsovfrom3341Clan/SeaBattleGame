#include "ScannerCommand.h"

#include "ScannerSettings.h"
#include "ScannerResult.h"
#include "AbilityResultHandler.h"
#include "Game.h"

#include <iostream>

ScannerCommand::ScannerCommand(int participantIndex, Coords coords):
	mParticipantIndex(participantIndex), mCoords(coords) {}

void ScannerCommand::execute(Game& game)
{
	AbilityResultHandler handler;
	ScannerSettings scSettings(game.getParticipant(mParticipantIndex)->mField, mCoords, handler);
	game.castAbility(&scSettings);
	if(handler.getResult() != nullptr)
		std::cout << dynamic_cast<ScannerResult*>(handler.getResult())->getResult();
}