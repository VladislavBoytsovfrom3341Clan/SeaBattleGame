#include "Game.h"

#include "ShipPosState.h"
#include "AttackState.h"
#include "ShipPlacementException.h"
#include "Player.h"
#include "Bot.h"


Game::Game(GameSettings& settings):
    mSettings(settings)
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

void Game::newGame()
{
    mState = new ShipPosState(mInfo);
    mInfo.mMoveIndex = 0;
    mInfo.mRoundCount = 1;
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

const GameInfo& Game::getInfo()
{
    return mInfo;
}

void Game::save()
{
    GameSaver mSaver(mInfo);
    FileHandler mHandler("testsave.txt", true);
    mHandler.write(mSaver);
}

void Game::load()
{
    GameSaver mSaver(mInfo);
    FileHandler mHandler("testsave.txt", false);
    mHandler.read(mSaver);
}
