#ifndef GAME_SAVER_H
#define GAME_SAVER_H

#include "GameInfo.h"

#include <iostream>

class GameSaver
{
	GameInfo& mInfo;

public:

	GameSaver(GameInfo& info);

	friend std::ifstream& operator>>(std::ifstream& is, GameSaver& state);

	friend std::ofstream& operator<<(std::ofstream& os, GameSaver& state);
};

#endif