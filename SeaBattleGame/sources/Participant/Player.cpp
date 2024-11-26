#include "Player.h"

#include "GameController.h"
#include "ShipPlacementException.h"
#include "AttackCommand.h"

#include <iostream>

void Player::placeShips()
{
	Coords coords = { 0, 0 };
    while (mShipManager->getInactiveShipsNumber() > 0)
    {
        try
        {
            Battleship& ship = mShipManager->getInactiveShip(0);
            mField->setShip(ship, { coords.x, coords.y }, Orientation::vertical);
            mShipManager->setShipActive(0);
        }
        catch (ShipPlacementException& e)
        {
            std::cout << e.what();
        }
        coords.x += 2;
    }
}

void Player::act()
{
    mController->acceptCommand(this->getAction());
}

ICommand* Player::getAction()
{
    return mInput.readCommand();
}