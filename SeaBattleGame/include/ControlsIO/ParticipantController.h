#ifndef PARTICIPANT_CONTROLLER_H
#define PARTICIPANT_CONTROLLER_H

#include "ICommand.h"
#include "Participant.h"
#include "GameObserver.h"

class ParticipantController
{
protected:
	Participant* mParticipant;
	GameObserver mObserver;
public:

	virtual ICommand* getAction() = 0;

	void setParticipant(Participant* participant);

	bool isReady();

	virtual void observe(GameInfo& gInfo, int pIndex);
};

#endif