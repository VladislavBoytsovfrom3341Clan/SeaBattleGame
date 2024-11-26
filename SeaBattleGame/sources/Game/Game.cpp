#include "Game.h"

#include "ShipPlacementException.h"
#include "Player.h"
#include "Bot.h"
#include "GameController.h"

#include <iostream>

Game::Game(Coords fieldSize)
{
    mFieldSize = fieldSize;
    mState = new GameState;
}

void Game::addPlayerByController(GameController& controller)
{
    Player* newPlayer = new Player(&controller, mFieldSize, mDefaultShips);
    mParticipants.push_back(newPlayer);
    newPlayer->placeShips();
    mPlayersNumber++;
    mParticipantsNumber++;
}

void Game::setBotsNumber(int number)
{
    mBotsNumber = number;
    mParticipantsNumber = number + mPlayersNumber;
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
            GameController* newController = new GameController(this);
            mParticipants[i] = new Bot(newController, mFieldSize, mDefaultShips);
            mParticipants[i]->placeShips();
        }
    }
}

//returns True, if there are alive players, otherwise False
bool Game::gameRoundCycle()
{
    while (this->countAliveParticipants() > 1)
    {
        Participant* currentParticipant = this->getCurrentParticipant();
        currentParticipant->act();
        this->Display();
        mMoveIndex++;
    }
    std::cout << "Round " << mRoundCount + 1 << " finished!\n";
    mRoundCount++;
    if (this->countAlivePlayers())
        return true;
    return false;
}

void Game::standartGameCycle()
{
    for (int i = 0; i < mBotsNumber; i++)
    {
        GameController* newController = new GameController(this);
        Bot* newBot = new Bot(newController, mFieldSize, mDefaultShips);
        mParticipants.push_back(newBot);
        newBot->placeShips();
    }
    while (this->countAlivePlayers() > 0)
    {
        std::cout << "\nNew round has started!\n";
        this->gameRoundCycle();
        this->regenerateBots();
    }
    std::cout << "Game Over!\n";
}

Participant* Game::getCurrentParticipant()
{
    int curIndex = mMoveIndex % mParticipantsNumber;
    int startIndex = curIndex;
    Participant* currentParticipant;
    do
    {
        currentParticipant = mParticipants[curIndex];
        curIndex = (++curIndex) % mParticipantsNumber;
    } while (!(currentParticipant->isAlive()) && curIndex != startIndex);
    if (startIndex == curIndex)
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