#include "DoubleDamageCommand.h"

#include "Game.h"
#include "DoubleDamage.h"
#include "DoubleDamageSettings.h"

//gets current Participant, then his multiplier,
//builds settings for DoubleDamage
//and then calls Game::castAbility()
void DoubleDamageCommand::execute(Game& game)
{
	int& multiplier = game.getCurrentParticipant()->mDamageMultiplier;
	DoubleDamageSettings ddSettings(multiplier);
	game.castAbility(&ddSettings);
}
