#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

#include "Coords.h"

#include <vector>

struct GameSettings
{
	Coords mFieldSize = { 5, 5 };
	std::vector<std::pair<int, int>> mDefaultShips{ {1, 1} };
};

#endif