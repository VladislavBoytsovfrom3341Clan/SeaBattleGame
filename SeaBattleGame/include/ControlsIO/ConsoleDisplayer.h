#ifndef CONSOLE_DISPLAYER_H
#define CONSOLE_DISPLAYER_H

#include "GameInfo.h"

class ConsoleDisplayer
{
	void printShip(Battleship& ship);

	void printShipsInManager(ShipManager& manager);

	void printAbilityManager(AbilityManager& aManager);

	void drawFriendField(Battlefield& field);

	void drawEnemyField(Battlefield& field);

public:

	ConsoleDisplayer() = default;

	void display(GameInfo& gInfo, int pIndex);
};

#endif