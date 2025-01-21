#ifndef PARTICIPANT_CONTROLLER_H
#define PARTICIPANT_CONTROLLER_H

#include "ICommand.h"
#include "Participant.h"
#include "GameObserver.h"
#include "Game.h"

#include <stdexcept>
#include <memory>

class ParticipantController
{
protected:
	int mIndex = 0;
	std::shared_ptr<const Participant> mParticipant;
	GameObserver mObserver;

public:
	ParticipantController(Game& game, int index);

	virtual ICommand* getAction() = 0;

	void setParticipant(std::shared_ptr<const Participant> participant);

	bool isReady() const;

	void handleException(std::exception& exp);

	virtual void observe(Game& game, int pIndex);

	virtual ~ParticipantController();
};

#endif