#include"Shelling.h"
#include<ctime>
#include<iostream>

Shelling::Shelling(ShellingSettings* shSettings):
mShipManager(shSettings->mManager){}

//Simply chooses random ship from list of active,
//then chooses random segment of chosen ship
//and calls damageSegment() on it
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