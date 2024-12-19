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

	void display(GameInfo& gInfo, int pIndex);

	void printShip(Battleship& ship);

	void printShipsInManager(ShipManager& manager);

	void printAbilityManager(AbilityManager& aManager);

	void drawFriendField(Battlefield& field);

	void drawEnemyField(Battlefield& field);

	void printScannerResult(ScannerResult& scRes);

	void printNewRound();

	void printNewGame();

	void printErrorMessage(const char* str);
};

#endif