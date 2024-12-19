#include "Game.h"
#include "GameController.h"
#include "GameSettings.h"
#include "PlayerController.hpp"
#include "ConcreteGameDisplayer.hpp"
#include "ConsoleDisplayer.h"

int main()
{
    GameSettings sts = { {10, 10}, {{1, 3}}};
    Game my_game(sts);
    GameController myController(my_game, sts);

    ConcreteGameDisplayer<ConsoleDisplayer> playerDisplayer;
    PlayerController<CLIInput> plC(my_game, 0, &playerDisplayer);
    myController.addPlayerController(plC);
    myController.addBots(2);
    myController.startGame();
}