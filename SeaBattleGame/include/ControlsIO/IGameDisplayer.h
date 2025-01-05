#ifndef I_GAME_DISPLAYER_H
#define I_GAME_DISPLAYER_H

#include "GameInfo.h"
#include "AbilityResult.h"

#include <stdexcept>

class IGameDisplayer
{
public:
	virtual void display(const GameInfo& gInfo, int pIndex) = 0;

	virtual void displayShipPositioning(const GameInfo& gInfo, int pIndex) = 0;

	virtual void displayAbilityResult(const AbilityResult& result) = 0;

	virtual void informNewRound() = 0;

	virtual void informNewGame() = 0;

	virtual void informError(const std::exception& exp) = 0;
};

#endif