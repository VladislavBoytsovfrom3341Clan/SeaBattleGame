#ifndef PARTICIPANT_CONTROLLER_H
#define PARTICIPANT_CONTROLLER_H

#include "ICommand.h"
#include "Participant.h"
#include "GameObserver.h"
#include "Game.h"

#include <stdexcept>

class ParticipantController
{
protected:
	int mIndex = 0;
	Participant* mParticipant = nullptr;
	GameObserver mObserver;
public:
	ParticipantController(Game& game, int index);

	virtual ICommand* getAction() = 0;

	void setParticipant(Participant* participant);

	bool isReady();

	void handleException(std::exception& exp);

	virtual void observe(Game& game, int pIndex);
};

#endif