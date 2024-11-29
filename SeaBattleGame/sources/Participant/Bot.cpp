#include "Bot.h"

Bot::Bot(Coords fieldSize, std::vector<std::pair<int, int>> shipList) :
	Participant(fieldSize, shipList) {
}

Bot::Bot(Battlefield field, std::vector<Battleship*> inactive, std::vector<Battleship*> active) :
	Participant(field, inactive, active) {
}

Bot::Bot(const Bot& copy)
{
	mField = copy.mField;
	mShipManager = copy.mShipManager;
	mDamageMultiplier = copy.mDamageMultiplier;
}