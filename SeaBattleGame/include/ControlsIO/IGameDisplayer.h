#ifndef I_GAME_DISPLAYER_H
#define I_GAME_DISPLAYER_H

#include "GameInfo.h"
#include "AbilityResult.h"

class IGameDisplayer
{
public:
	virtual void display(GameInfo& gInfo, int pIndex) = 0;

	virtual void displayShipPositioning(GameInfo& gInfo, int pIndex) = 0;

	virtual void displayAbilityResultResult(AbilityResult& result) = 0;
};

#endif