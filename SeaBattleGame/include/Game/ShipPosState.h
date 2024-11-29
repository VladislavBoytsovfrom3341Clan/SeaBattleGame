#ifndef SHIP_POS_STATE_H
#define SHIP_POS_STATE_H

#include "GameState.h"

#include "GameInfo.h"
#include "Participant.h"

class ShipPosState : public GameState
{
	GameInfo& mInfo;

public:

	ShipPosState(GameInfo& info);

	void placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation) override;

	void castAbility(IAbilitySettings* settings) override;

	void attack(int index, Coords coords, int damage) override;
};

#endif