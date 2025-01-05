#ifndef CONSOLE_DISPLAYER_H
#define CONSOLE_DISPLAYER_H

#include "GameInfo.h"
#include "ScannerResult.h"
#include "Player.h"

#include <string>

class ConsoleDisplayer
{
public:

	ConsoleDisplayer() = default;

	void display(const GameInfo& gInfo, int pIndex) const;

	void printShip(const Battleship& ship) const;

	void printShipsInManager(const ShipManager& manager) const;

	void printAbilityManager(const AbilityManager& aManager) const;

	void drawFriendField(const Battlefield& field) const;

	void drawEnemyField(const Battlefield& field) const;

	void printScannerResult(const ScannerResult& scRes) const;

	void printNewRound() const;

	void printNewGame() const;

	void printErrorMessage(const char* str) const;
};

#endif