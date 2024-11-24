#include<iostream>

#include "Game.h"

//WE USE MAIN AS DEBUGGING BASE
int main()
{
    Game my_game(1, 4);
    my_game.shipPositioning();
    my_game.standartGameCycle();
}