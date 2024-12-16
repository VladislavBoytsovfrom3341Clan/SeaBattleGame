#include "Player.h"


Player::Player(Coords fieldSize, std::vector<std::pair<int, int>> shipList) :
	Participant(fieldSize, shipList) {
}

Player::Player(Battlefield field, std::vector<Battleship*> inactive, std::vector<Battleship*> active, AbilityManager aManager):
	Participant(field, inactive, active) 
{
	mAbilityManager = aManager;
}
