#include"Shelling.h"
#include<ctime>
#include<iostream>

Shelling::Shelling(ShellingSettings* shSettings):
mShipManager(shSettings->mManager){}

void Shelling::cast()
{
    int shipNumber = mShipManager.getActiveShipsNumber();
    if(shipNumber == 0)
        return;
    int shipRandomIndex = rand() % shipNumber;
    Battleship& randomShip = mShipManager.getActiveShip(shipRandomIndex);
    int randomSegmentIndex = rand() % randomShip.getLength();
    randomShip.damageSegment(randomSegmentIndex, 1);
}