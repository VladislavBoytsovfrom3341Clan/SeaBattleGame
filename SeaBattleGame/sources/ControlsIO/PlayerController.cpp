#include "PlayerController.h"

#include "ShipPlacementException.h"

#include <iostream>

ICommand* PlayerController::getAction()
{
	return mInput.readCommand();
}
