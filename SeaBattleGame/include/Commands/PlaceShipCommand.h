#ifndef PLACE_SHIP_COMMAND_H
#define PLACE_SHIP_COMMAND_H

#include "ICommand.h"
#include "Coords.h"

class PlaceShipCommand : public ICommand
{
	int mShipIndex;
	Coords mCoords;
	Orientation mOrientation;

public:

	PlaceShipCommand(int shipIndex, Coords coords, Orientation orientation);

	void execute(class Game& game) override;
};

#endif