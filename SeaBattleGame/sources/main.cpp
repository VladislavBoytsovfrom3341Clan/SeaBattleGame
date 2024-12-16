#include<iostream>

#include "Game.h"
#include "GameController.h"
#include "GameSettings.h"
#include "PlayerController.h"
#include "FileHandler.h"



//no OOP only as DEBUG func
void printShip(Battleship& ship);


//no OOP only as DEBUG func
void printShipsInManager(ShipManager& manager);


//WE USE MAIN AS DEBUGGING BASE
int main()
{
    GameSettings sts = { {10, 10}, {{4, 1}}};
    Game my_game(sts);
    GameController myController(my_game, sts);
    PlayerController plC;
    myController.addPlayerController(plC);
    myController.addBots(2);
    myController.startGame();

}