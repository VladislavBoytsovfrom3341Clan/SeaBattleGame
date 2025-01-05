#include "Bot.h"

Bot::Bot(Coords fieldSize, std::vector<std::pair<int, int>> shipList) :
	Participant(fieldSize, shipList) {
}

Bot::Bot(Battlefield field, std::vector<std::shared_ptr<Battleship>> inactive, std::vector<std::shared_ptr<Battleship>> active) :
	Participant(field, inactive, active) {
}
