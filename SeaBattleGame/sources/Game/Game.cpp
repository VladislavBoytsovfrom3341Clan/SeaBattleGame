#include "Game.h"

#include "ShipPosState.h"
#include "AttackState.h"
#include "ShipPlacementException.h"
#include "Player.h"
#include "Bot.h"

#include <iostream>

Game::Game(GameSettings& settings):
    mSettings(settings)
{
    mState = new ShipPosState(mParticipants, mMoveIndex, mParticipantsNumber);
}

void Game::addParticipant(Participant* participant)
{
    mParticipants.push_back(participant);
    mParticipantsNumber++;
}

Participant* Game::resetPlayer(int index)
{
    delete mParticipants[index];
    mParticipants[index] = new Player(mSettings.mFieldSize, mSettings.mDefaultShips);
    return mParticipants[index];
}

Participant* Game::resetBot(int index)
{
    delete mParticipants[index];
    mParticipants[index] = new Bot(mSettings.mFieldSize, mSettings.mDefaultShips);
    return mParticipants[index];
}

void Game::placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation)
{
    mState->placeShip(playerIndex, shipIndex, coords, orientation);
}

void Game::attack(int index, Coords coords)
{
    int damage = mParticipants[this->getCurrentParticipantIndex()]->mDamageMultiplier;
    mState->attack(index, coords, damage);
}

void Game::castAbility(IAbilitySettings* settings)
{
    mState->castAbility(settings);
}

void Game::newMove()
{
    mState = new AttackState(mParticipants, mMoveIndex, mParticipantsNumber);
}

void Game::newRound()
{
    mState = new ShipPosState(mParticipants, mMoveIndex, mParticipantsNumber);
    mMoveIndex = 0;
    mRoundCount++;
}

int Game::getCurrentParticipantIndex()
{
    int endIndex = mMoveIndex + mParticipantsNumber;
    Participant* currentParticipant = mParticipants[mMoveIndex % mParticipantsNumber];
    while (!(currentParticipant->isAlive()) && mMoveIndex < endIndex)
        currentParticipant = mParticipants[(++mMoveIndex) % mParticipantsNumber];
    if (endIndex == mMoveIndex)
        throw std::logic_error("No Alive Participants");
    return mMoveIndex % mParticipantsNumber;
}

Participant* Game::getCurrentParticipant()
{
    return mParticipants[this->getCurrentParticipantIndex()];
}

Participant* Game::getParticipant(int index)
{
    return mParticipants[index];
}

int Game::countAliveParticipants()
{
    int count = 0;

    for (Participant* participant : mParticipants)
    {
        if (participant->isAlive())
            count++;
    }
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
        {
            if (i->isAlive())
                count++;
        }
    }
    return count;
}








#include "AbilityManager.h"
#include "AbilityType.h"

void printAbility(AbilityType t)
{
    switch (t)
    {
    case AbilityType::DoubleDamage:
        std::cout << "DoubleDamage\n";
        break;
    case AbilityType::Scanner:
        std::cout << "Scanner\n";
        break;
    case AbilityType::Shelling:
        std::cout << "Shelling\n";
    }
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
        std::cout << "\nParticipant #" << i <<"   " << mParticipants[i]->isAlive() << '\n';
        if(!(mParticipants[i]->mAbilityManager.empty()))
            printAbility(mParticipants[i]->mAbilityManager.getFirstAbility());
        printShipsInManager(mParticipants[i]->mShipManager);
        mParticipants[i]->mField.display();
    }
}