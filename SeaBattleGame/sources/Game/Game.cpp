#include "Game.h"

#include "ShipPlacementException.h"
#include "Player.h"
#include "Bot.h"

#include <iostream>

Game::Game(Coords fieldSize)
{
    mFieldSize = fieldSize;
    mState = new GameState;
    Participant* player = new Player(mFieldSize, mDefaultShips);
    mParticipants.push_back(player);
    player->placeShips();
    mParticipantsNumber++;
    mPlayersNumber++;
}

void Game::generateBots(int number)
{
    mBotsNumber = number;
    mParticipantsNumber = number + mPlayersNumber;
    for (int i = 0; i < mBotsNumber; i++)
    {
        Bot* newBot = new Bot(mFieldSize, mDefaultShips);
        mParticipants.push_back(newBot);
        newBot->placeShips();
    }
}

bool Game::attackParticipant(int index, Coords coords)
{
    return mParticipants[index]->mField->attackCell(coords);
}

void Game::shipPositioning()
{
    for (int i = 0; i < mParticipantsNumber; i++)
    {
        mParticipants[i]->placeShips();
    }
}

void Game::regenerateBots()
{
    for (int i = 0; i < mBotsNumber + mPlayersNumber; i++)
    {
        if (typeid(*(mParticipants[i])) == typeid(Bot))
        {
            std::cout << "regenerating bot " << i << '\n';
            delete mParticipants[i];
            mParticipants[i] = new Bot(mFieldSize, mDefaultShips);
            mParticipants[i]->placeShips();
        }
    }
}

void Game::newMove()
{
    mMoveIndex++;
}

void Game::newRound()
{
    mMoveIndex = 0;
    mRoundCount++;
    this->regenerateBots();
}

Participant* Game::getCurrentParticipant()
{
    int endIndex = mMoveIndex + mParticipantsNumber;
    Participant* currentParticipant = mParticipants[mMoveIndex % mParticipantsNumber];
    while (!(currentParticipant->isAlive()) && mMoveIndex < endIndex)
        currentParticipant = mParticipants[(++mMoveIndex) % mParticipantsNumber];
    if (endIndex == mMoveIndex)
        throw std::logic_error("No Alive Participants");
    return currentParticipant;
}

void createBot(int index);

void createPlayer(int index);

void Game::removeParticipant(int index)
{
    mParticipants.erase(mParticipants.begin() + index);
}

int Game::countAliveParticipants()
{
    int count = 0;
    for (Participant* participant : mParticipants)
        if (participant->isAlive())
            count++;
    return count;
}

int Game::countAliveBots()
{
    int count = 0;
    for (Participant* i : mParticipants)
    {
        if (typeid(*i) == typeid(Bot))
            if (i->isAlive())
                count++;
    }
    return count;
}

int Game::countAlivePlayers()
{
    int count = 0;
    for (Participant* i : mParticipants)
    {
        if (typeid(*i) == typeid(Player))
            if (i->isAlive())
                count++;
    }
    return count;
}










//no OOP only as DEBUG func
void printShip(const Battleship& ship)
{
    auto segments = ship.getShipCondition();
    std::cout << "Ship " << ship.getLength() << " condition:\n\t";
    for (auto segment : segments)
        std::cout << int(segment) << ' ';
    std::cout << '\n';
}

//no OOP only as DEBUG func
void printShipsInManager(const ShipManager& manager)
{
    std::cout << "Inactive ships in manager: " << manager.getInactiveShipsNumber() << '\n';
    for (int i = 0; i < manager.getInactiveShipsNumber(); i++)
        printShip(manager.getInactiveShip(i));

    std::cout << "Active ships in manager: " << manager.getActiveShipsNumber() << '\n';
    for (int i = 0; i < manager.getActiveShipsNumber(); i++)
        printShip(manager.getActiveShip(i));
}

void Game::Display()
{
    std::cout << "\nMove " << mMoveIndex << '\n';
    for (int i = 0; i < mParticipants.size(); i++)
    {
        std::cout << "\nParticipant #" << i << '\n';
        printShipsInManager(*(mParticipants[i]->mShipManager));
        mParticipants[i]->mField->display();
    }
}