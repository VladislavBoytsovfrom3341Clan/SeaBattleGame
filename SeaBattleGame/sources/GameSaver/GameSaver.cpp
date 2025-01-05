#include "GameSaver.h"

#include "GameInfo.h"
#include "Player.h"
#include "Bot.h"

#include <vector>

GameSaver::GameSaver(GameInfo& info) :
	mInfo(info) {}

std::ifstream& operator>>(std::ifstream& is, GameSaver& state)
{
	is >> state.mInfo.mRoundCount;
	is >> state.mInfo.mMoveIndex;
	is >> state.mInfo.mParticipantsNumber;
	is >> state.mInfo.mPlayersNumber;
	is >> state.mInfo.mBotsNumber;

	std::vector<Participant*> tempParticipants(state.mInfo.mParticipantsNumber);
	for (int i = 0; i < state.mInfo.mParticipantsNumber; i++)
	{
		int index;
		is >> index;
		int entity;
		is >> entity;
		AbilityManager aManager;
		is >> aManager;
		int activeShipsNumber;
		is >> activeShipsNumber;
		std::vector<std::shared_ptr<Battleship>> activeShips(activeShipsNumber);
		for (int j = 0; j < activeShipsNumber; j++)
		{
			activeShips[j] = std::make_shared<Battleship>();
			is >> *(activeShips[j]);
		}
		Battlefield field;
		is >> field;
		for (std::shared_ptr<Battleship> ship : activeShips)
		{
			field.setShip(*ship, ship->getPosition(), ship->getOrientation());
		}
		if (entity == 0)
			tempParticipants[i] = new Bot(field, {}, activeShips);
		else
			tempParticipants[i] = new Player(field, {}, activeShips, aManager);
	}
	state.mInfo.mParticipants.resize(state.mInfo.mParticipantsNumber);
	for (int i=0; i<state.mInfo.mParticipantsNumber; i++)
	{
		state.mInfo.mParticipants[i] = tempParticipants[i];
	}
	return is;
}

std::ofstream& operator<<(std::ofstream& os, GameSaver& state)
{
	os << state.mInfo.mRoundCount << '\n';
	os << state.mInfo.mMoveIndex << '\n';
	os << state.mInfo.mParticipantsNumber << '\n';
	os << state.mInfo.mPlayersNumber << '\n';
	os << state.mInfo.mBotsNumber << '\n';
	for (int i = 0; i < state.mInfo.mParticipantsNumber; i++)
	{
		//participants index (same as in vector)
		os << i << '\n';

		//0 for Bot and 1 for Player
		if (typeid(*(state.mInfo.mParticipants[i])) == typeid(Bot))
			os << 0 << '\n';
		else
			os << 1 << '\n';
		os << state.mInfo.mParticipants[i]->mAbilityManager;
		int activeShipsNum = state.mInfo.mParticipants[i]->mShipManager.getActiveShipsNumber();
		os << activeShipsNum <<'\n';
		for (int j = 0; j < activeShipsNum; j++)
		{
			os<<state.mInfo.mParticipants[i]->mShipManager.getActiveShip(j);
		}
		os << state.mInfo.mParticipants[i]->mField;
	}
	return os;
}
