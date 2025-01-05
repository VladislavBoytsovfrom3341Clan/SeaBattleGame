#include "PlaceShipCommand.h"

#include "Game.h"

PlaceShipCommand::PlaceShipCommand(int shipIndex, Coords coords, Orientation orientation) :
	mShipIndex(shipIndex), mCoords(coords), mOrientation(orientation) { }

void PlaceShipCommand::execute(class Game& game)
{
	game.placeShip(game.getCurrentParticipantIndex(), mShipIndex, mCoords, mOrientation);
}
