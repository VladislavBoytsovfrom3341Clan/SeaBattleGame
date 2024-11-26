#include<iostream>

#include "Game.h"
#include "GameController.h"

//WE USE MAIN AS DEBUGGING BASE
int main()
{
    Game my_game({5, 5});
    GameController myController(&my_game);
    my_game.addPlayerByController(myController);
    my_game.standartGameCycle();
}