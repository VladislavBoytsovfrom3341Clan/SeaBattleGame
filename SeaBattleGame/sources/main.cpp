#include<iostream>

#include "Game.h"
#include "GameController.h"
#include "GameSettings.h"
#include "PlayerController.h"

//WE USE MAIN AS DEBUGGING BASE
int main()
{
    GameSettings sts;
    Game my_game(sts);
    GameController myController(my_game, sts);
    PlayerController plC;
    myController.addPlayerController(plC);
    myController.addBots(2);
    myController.startGame();
}