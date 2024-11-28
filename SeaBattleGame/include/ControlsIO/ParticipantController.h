#ifndef PARTICIPANT_CONTROLLER_H
#define PARTICIPANT_CONTROLLER_H

#include "ICommand.h"
#include "Participant.h"

class ParticipantController
{
protected:
	Participant* mParticipant;
public:

	virtual ICommand* getAction() = 0;

	void setParticipant(Participant* participant);

	bool isReady();
};

#endif