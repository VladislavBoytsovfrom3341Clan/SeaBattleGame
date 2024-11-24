#include "Game.h"

#include "ShipPlacementException.h"
#include "Player.h"
#include "Bot.h"

#include <iostream>

Game::Game(int playersNumber, int botsNumber)
{
	mState = new GameState(playersNumber, botsNumber);
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
        ICommand* command = currentParticipant->getAction();
        command->execute(*mState);
        delete command;
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
               mState->createBot(i);
            else if (!(mState->getParticipant(i)->isAlive()))
               mState->createPlayer(i);
        }
        std::cout << "\nNew round has started!\n";
    }
    std::cout << "Game Over!\n";
}