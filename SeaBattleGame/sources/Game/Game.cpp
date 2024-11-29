#include "Game.h"

#include "ShipPosState.h"
#include "AttackState.h"
#include "ShipPlacementException.h"
#include "Player.h"
#include "Bot.h"

#include <iostream>

Game::Game(GameSettings& settings):
    mSettings(settings), mSaver(mInfo)
{
    mState = new ShipPosState(mInfo);
}

void Game::addParticipant(Participant* participant)
{
    mInfo.mParticipants.push_back(participant);
    mInfo.mParticipantsNumber++;
}

Participant* Game::resetPlayer(int index)
{
    delete mInfo.mParticipants[index];
    mInfo.mParticipants[index] = new Player(mSettings.mFieldSize, mSettings.mDefaultShips);
    return mInfo.mParticipants[index];
}

Participant* Game::resetBot(int index)
{
    delete mInfo.mParticipants[index];
    mInfo.mParticipants[index] = new Bot(mSettings.mFieldSize, mSettings.mDefaultShips);
    return mInfo.mParticipants[index];
}

void Game::placeShip(int playerIndex, int shipIndex, Coords coords, Orientation orientation)
{
    mState->placeShip(playerIndex, shipIndex, coords, orientation);
}

void Game::attack(int index, Coords coords)
{
    int damage = mInfo.mParticipants[this->getCurrentParticipantIndex()]->mDamageMultiplier;
    mState->attack(index, coords, damage);
}

void Game::castAbility(IAbilitySettings* settings)
{
    mState->castAbility(settings);
}

void Game::newMove()
{
    mState = new AttackState(mInfo);
}

void Game::newRound()
{
    mState = new ShipPosState(mInfo);
    mInfo.mMoveIndex = 0;
    mInfo.mRoundCount++;
}

int Game::getCurrentParticipantIndex()
{
    int endIndex = mInfo.mMoveIndex + mInfo.mParticipantsNumber;
    Participant* currentParticipant = mInfo.mParticipants[mInfo.mMoveIndex % mInfo.mParticipantsNumber];
    while (!(currentParticipant->isAlive()) && mInfo.mMoveIndex < endIndex)
        currentParticipant = mInfo.mParticipants[(++mInfo.mMoveIndex) % mInfo.mParticipantsNumber];
    if (endIndex == mInfo.mMoveIndex)
        throw std::logic_error("No Alive Participants");
    return mInfo.mMoveIndex % mInfo.mParticipantsNumber;
}

Participant* Game::getCurrentParticipant()
{
    return mInfo.mParticipants[this->getCurrentParticipantIndex()];
}

Participant* Game::getParticipant(int index)
{
    return mInfo.mParticipants[index];
}

int Game::countAliveParticipants()
{
    int count = 0;

    for (Participant* participant : mInfo.mParticipants)
    {
        if (participant->isAlive())
            count++;
    }
    return count;
}

int Game::countAliveBots()
{
    int count = 0;
    for (Participant* i : mInfo.mParticipants)
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
    for (Participant* i : mInfo.mParticipants)
    {
        if (typeid(*i) == typeid(Player))
        {
            if (i->isAlive())
                count++;
        }
    }
    return count;
}

void Game::save()
{
    std::cout << "+Game start\n";
    mHandler.openWrite();
    mHandler.write(mSaver);
    mHandler.closeWrite();
    std::cout << "+Game End\n";
}

void Game::load()
{
    std::cout << "+Game start\n";
    mHandler.openRead();
    mHandler.read(mSaver);
    mHandler.closeRead();
    std::cout << "+Game End\n";
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
void printShip(Battleship& ship)
{
    auto segments = ship.getShipCondition();
    std::cout << "Ship " << ship.getPosition().toString() << " condition:\n\t";
    for (auto segment : segments)
        std::cout << int(segment) << ' ';
    std::cout << '\n';
}

//no OOP only as DEBUG func
void printShipsInManager(ShipManager& manager)
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
    std::cout << "\nMove " << mInfo.mMoveIndex << '\n';
    for (int i = 0; i < mInfo.mParticipants.size(); i++)
    {
        std::cout << "\nParticipant #" << i <<"   " << mInfo.mParticipants[i]->isAlive() << '\n';
        if(!(mInfo.mParticipants[i]->mAbilityManager.empty()))
            printAbility(mInfo.mParticipants[i]->mAbilityManager.getFirstAbility());
        printShipsInManager(mInfo.mParticipants[i]->mShipManager);
        mInfo.mParticipants[i]->mField.display();
    }
}