#ifndef I_GAME_DISPLAYER_H
#define I_GAME_DISPLAYER_H

#include "GameInfo.h"

class IGameDisplayer
{
public:
	virtual void display(GameInfo& gInfo, int pIndex) = 0;
};

#endif