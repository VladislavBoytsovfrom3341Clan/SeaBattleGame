#ifndef PLACE_SHIP_COMMAND_H
#define PLACE_SHIP_COMMAND_H

#include "ICommand.h"
#include "Coords.h"


/*
* Command orders to place
* some ship of CURRENT player
* to some position
*/
class PlaceShipCommand : public ICommand
{
	int mShipIndex;
	Coords mCoords;
	Orientation mOrientation;

public:

	PlaceShipCommand(int shipIndex, Coords coords, Orientation orientation);

	//Orders to place ship at received position
	void execute(class Game& game) override;
};

#endif