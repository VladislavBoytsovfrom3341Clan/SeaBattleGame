#include "Player.h"


Player::Player(Coords fieldSize, std::vector<std::pair<int, int>> shipList) :
	Participant(fieldSize, shipList) {
}

Player::Player(Battlefield field, std::vector<Battleship*> inactive, std::vector<Battleship*> active) :
	Participant(field, inactive, active) {
}

Player::Player(const Player& copy)
{
	mField = copy.mField;
	mShipManager = copy.mShipManager;
	mDamageMultiplier = copy.mDamageMultiplier;
}