#include "Game.h"

#include "ShipPlacementException.h"
#include "Player.h"
#include "Bot.h"
#include "GameController.h"

#include <iostream>

Game::Game(int playersNumber, int botsNumber)
{
	mState = new GameState();
    for (int i = 0; i < playersNumber; i++)
    {
        GameController* newController = new GameController(*mState);
        Player* newPlayer = new Player(newController, {5, 5}, { {1, 1}});
        mState->acceptParticipant(newPlayer);
    }
    for (int i = 0; i < botsNumber; i++)
    {
        GameController* newController = new GameController(*mState);
        Bot* newBot = new Bot(newController, { 5, 5 }, { {1, 1}});
        mState->acceptParticipant(newBot);
    }
}

void Game::shipPositioning()
{
    for (int i = 0; i < mState->getParticipantsNumber(); i++)
    {
        mState->getParticipant(i)->placeShips();
    }
}

//returns True, if there are alive players, otherwise False
bool Game::gameRoundCycle()
{
    while (mState->countAliveParticipants() > 1)
    {
        Participant* currentParticipant = mState->getCurrentParticipant(mMoveIndex);
        currentParticipant->act();
        mState->Display(mMoveIndex);
        mMoveIndex++;
    }
    std::cout << "Round " << mRoundCount + 1 << " finished!\n";
    mRoundCount++;
    if (mState->countAlivePlayers())
        return true;
    return false;
}

void Game::standartGameCycle()
{
    while (this->gameRoundCycle() == true)
    {
        for (int i = 0; i < mState->getParticipantsNumber(); i++)
        {
            if (typeid(*(mState->getParticipant(i))) == typeid(Bot))
            {
                mState->createBot(i);
                mState->getParticipant(i)->placeShips();
            }
        }
        std::cout << "\nNew round has started!\n";
    }
    std::cout << "Game Over!\n";
}