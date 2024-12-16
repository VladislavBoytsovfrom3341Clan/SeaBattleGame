#include "DoubleDamageCommand.h"

#include "Game.h"
#include "DoubleDamage.h"
#include "DoubleDamageSettings.h"

void DoubleDamageCommand::execute(Game& game)
{
	int& multiplier = game.getCurrentParticipant()->mDamageMultiplier;
	DoubleDamageSettings ddSettings(multiplier);
	game.castAbility(&ddSettings);
}
