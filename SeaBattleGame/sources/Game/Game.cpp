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

void Game::addParticipant(std::shared_ptr<Participant> participant)
{
    mInfo.mParticipants.emplace_back(participant);
    mInfo.mParticipantsNumber++;
}

std::shared_ptr<Participant> Game::resetPlayer(int index)
{
    //delete mInfo.mParticipants[index];
    mInfo.mParticipants[index] = std::make_shared<Player>(mSettings.mFieldSize, mSettings.mDefaultShips);
    return mInfo.mParticipants[index];
}

std::shared_ptr<Participant> Game::resetBot(int index)
{
    //delete mInfo.mParticipants[index];
    mInfo.mParticipants[index] = std::make_shared<Bot>(mSettings.mFieldSize, mSettings.mDefaultShips);
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
    delete mState;
    mState = new AttackState(mInfo);
}

void Game::newRound()
{
    delete mState;
    mState = new ShipPosState(mInfo);
    mInfo.mMoveIndex = 0;
    mInfo.mRoundCount++;
}

void Game::newGame()
{
    delete mState;
    mState = new ShipPosState(mInfo);
    mInfo.mMoveIndex = 0;
    mInfo.mRoundCount = 1;
}

int Game::getCurrentParticipantIndex() const
{
    return mState->getCurrentParticipantIndex();
}

std::shared_ptr<Participant> Game::getCurrentParticipant() const
{
    return mInfo.mParticipants[this->getCurrentParticipantIndex()];
}

std::shared_ptr<Participant> Game::getParticipant(int index) const
{
    return mInfo.mParticipants.at(index);
}

int Game::countAliveParticipants() const
{
    int count = 0;

    for (auto& participant : mInfo.mParticipants)
    {
        if (participant->isAlive())
            count++;
    }
    return count;
}

int Game::countAliveBots() const
{
    int count = 0;
    for (auto& i : mInfo.mParticipants)
    {
        if (typeid(*i) == typeid(Bot))
            if (i->isAlive())
                count++;
    }
    return count;
}

int Game::countAlivePlayers() const
{
    int count = 0;
    for (auto& i : mInfo.mParticipants)
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
    mNeedSync = true;
}

bool Game::checkSync()
{
    return mNeedSync;
}

void Game::synchronize()
{
    mNeedSync = false;
}

Game::~Game()
{
    delete mState;
}