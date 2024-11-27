#include "ShipPosState.h"

#include "Participant.h"

ShipPosState::ShipPosState(std::vector<Participant*>& participants) :
	mParticipants(participants) {}

bool ShipPosState::participantMayAct(int index)
{
	if (mParticipants[index]->mShipManager.getInactiveShipsNumber() > 0)
		return true;
	return false;
}

void ShipPosState::placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation)
{
	Battleship& ship = mParticipants[playerIndex]->mShipManager.getInactiveShip(shipIndex);
	mParticipants[playerIndex]->mField.setShip(ship, coords, orientation);
	mParticipants[playerIndex]->mShipManager.setShipActive(shipIndex);
}

void ShipPosState::attack(int index, Coords coords)
{
}
