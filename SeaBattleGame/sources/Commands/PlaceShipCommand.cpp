#include "PlaceShipCommand.h"

#include "Game.h"

PlaceShipCommand::PlaceShipCommand(int playerIndex, int shipIndex, Coords coords, Orientation orientation) :
	mPlayerIndex(playerIndex), mShipIndex(shipIndex), mCoords(coords), mOrientation(orientation) { }

void PlaceShipCommand::execute(class Game& game)
{
	game.placeShip(mPlayerIndex, mShipIndex, mCoords, mOrientation);
}
