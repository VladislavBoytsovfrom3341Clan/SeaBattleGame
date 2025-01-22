#ifndef GAME_INFO_H
#define GAME_INFO_H

#include "Participant.h"

#include <vector>
#include <memory>

struct GameInfo
{
	std::vector<std::shared_ptr<Participant>> mParticipants;
	int mMoveIndex = 0;
	int mRoundCount = 0;
	int mBotsNumber = 0;
	int mPlayersNumber = 0;
	int mParticipantsNumber = 0;
	bool mUsedAbility = false;
};

#endif