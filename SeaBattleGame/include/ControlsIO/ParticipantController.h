#ifndef PARTICIPANT_CONTROLLER_H
#define PARTICIPANT_CONTROLLER_H

#include "ICommand.h"
#include "Participant.h"
#include "GameObserver.h"

#include <stdexcept>

class ParticipantController
{
protected:
	Participant* mParticipant;
	GameObserver mObserver;
public:

	virtual ICommand* getAction() = 0;

	void setParticipant(Participant* participant);

	bool isReady();

	void handleException(std::exception& exp);

	virtual void observe(Game& game, int pIndex);
};

#endif