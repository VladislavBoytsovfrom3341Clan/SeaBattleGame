#include "ShipPosState.h"

#include "Participant.h"

ShipPosState::ShipPosState(std::vector<Participant*>& participants, int& moveIndex, int& participantsNumber) :
	mParticipants(participants), mMoveIndex(moveIndex), mParticipantsNumber(participantsNumber) {}

void ShipPosState::placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation)
{
	Battleship& ship = mParticipants.at(playerIndex)->mShipManager.getInactiveShip(shipIndex);
	mParticipants.at(playerIndex)->mField.setShip(ship, coords, orientation);
	mParticipants.at(playerIndex)->mShipManager.setShipActive(shipIndex);
}

void ShipPosState::castAbility(IAbilitySettings* settings)
{
}

void ShipPosState::attack(int index, Coords coords, int damage)
{
}
