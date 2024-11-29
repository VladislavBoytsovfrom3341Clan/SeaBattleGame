#include "ShipPosState.h"

#include "Participant.h"

ShipPosState::ShipPosState(GameInfo& info) :
	mInfo(info) {}

void ShipPosState::placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation)
{
	Battleship& ship = mInfo.mParticipants.at(playerIndex)->mShipManager.getInactiveShip(shipIndex);
	mInfo.mParticipants.at(playerIndex)->mField.setShip(ship, coords, orientation);
	mInfo.mParticipants.at(playerIndex)->mShipManager.setShipActive(shipIndex);
}

void ShipPosState::castAbility(IAbilitySettings* settings)
{
}

void ShipPosState::attack(int index, Coords coords, int damage)
{
}
