#include "ScannerCommand.h"

#include "ScannerSettings.h"
#include "ScannerResult.h"
#include "AbilityResultHandler.h"
#include "Game.h"

#include <iostream>

ScannerCommand::ScannerCommand(int participantIndex, Coords coords):
	mParticipantIndex(participantIndex), mCoords(coords) {}

//Builds scannerSettings and calls Game::castAbility()
void ScannerCommand::execute(Game& game)
{
	ScannerSettings scSettings(game.getParticipant(mParticipantIndex)->mField, mCoords, game.getCurrentParticipant()->mHandler);
	game.castAbility(&scSettings);
}