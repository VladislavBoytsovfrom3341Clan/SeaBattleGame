#include "GameState.h"

#include "ShipPlacementException.h"
#include "Player.h"
#include "Bot.h"

#include <iostream>
#include <cstdlib>

GameState::GameState(int PlayersNumber, int BotsNumber)
{
	for (int i = 0; i < PlayersNumber; i++)
		mParticipants.push_back(new Player(mFieldSize, { { 4, 1 }, { 3, 2 } }));
	for (int i = 0; i < BotsNumber; i++)
		mParticipants.push_back(new Bot(mFieldSize, { { 4, 1 }, { 3, 2 } }));
}

void GameState::createBot(int index)
{
    if (mParticipants[index] != nullptr)
        delete mParticipants[index];
    mParticipants[index] = new Bot(mFieldSize, { { 4, 1 }, { 3, 2 } });
}

void GameState::createPlayer(int index)
{
    if (mParticipants[index] != nullptr)
        delete mParticipants[index];
    mParticipants[index] = new Player(mFieldSize, { { 4, 1 }, { 3, 2 } });
}

Coords GameState::getFieldSize()
{
    return mFieldSize;
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

int GameState::countAliveParticipants()
{
    int count = 0;
    for (Participant* participant : mParticipants)
        if (participant->mShipManager->getAliveShipsNumber() != 0)
            count++;
    return count;
}

void GameState::attackParticipant(int index, Coords coords)
{
	mParticipants[index]->mField->attackCell(coords);
}

int GameState::getParticipantsNumber()
{
    return this->mParticipants.size();
}

int GameState::countAliveBots()
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

int GameState::countAlivePlayers()
{
    int count = 0;
    for (Participant* i : mParticipants)
    {
        if (typeid(*i) == typeid(Player))
        {
            if (i->isAlive())
                count++;
        }
    }
    return count;
}

Participant* GameState::getParticipant(int index)
{
    return this->mParticipants[index];
}

Participant* GameState::getCurrentParticipant(int moveIndex)
{
    int numOfParticipants = mParticipants.size();
    int curIndex = moveIndex % numOfParticipants;
    int startIndex = curIndex;
    Participant* currentParticipant;
    do
    {
        currentParticipant = mParticipants[curIndex];
        curIndex = (++curIndex) % numOfParticipants;
    } while (!(currentParticipant->isAlive()) && curIndex != startIndex);
    if (startIndex == curIndex)
        throw std::logic_error("No Alive Participants");
    return currentParticipant;
}

void GameState::Display(int moveIndex)
{
    std::cout << "\nMove " << moveIndex << '\n';
    for (int i = 0; i < mParticipants.size(); i++)
    {
        std::cout << "\nParticipant #" << i << '\n';
        std::cout << mParticipants[i]->getAction() << '\n';
        printShipsInManager(*(mParticipants[i]->mShipManager));
        mParticipants[i]->mField->display();
    }
}