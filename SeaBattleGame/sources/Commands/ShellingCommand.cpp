#include "ShellingCommand.h"

#include "ShellingSettings.h"

#include "Game.h"

ShellingCommand::ShellingCommand(int playerIndex) :
	mPlayerIndex(playerIndex) {}

//Builds shelling settings and calls Game::castAbility()
void ShellingCommand::execute(Game& game)
{
	ShellingSettings shSettings(game.getParticipant(mPlayerIndex)->mShipManager);
	game.castAbility(&shSettings);
}