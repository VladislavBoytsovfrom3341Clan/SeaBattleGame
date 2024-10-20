#include"Shelling.h"
#include<ctime>
#include<iostream>

void Shelling::cast()
{
    int shipNumber = mShipManager->getActiveShipsNumber();
    if(shipNumber == 0)
        return;
    int shipRandomIndex = rand() % shipNumber;
    Battleship& randomShip = mShipManager->getActiveShip(shipRandomIndex);
    int randomSegmentIndex = rand() % randomShip.getLength();
    randomShip.damageSegment(randomSegmentIndex, 1);
}