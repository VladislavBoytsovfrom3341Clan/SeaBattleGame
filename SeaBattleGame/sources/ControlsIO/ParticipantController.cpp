#include "ParticipantController.h"

ParticipantController::ParticipantController(Game& game, int index) :
	mObserver(game), mIndex(index) {
}

void ParticipantController::setParticipant(Participant* participant)
{
	mParticipant = participant;
}

bool ParticipantController::isReady() const
{
	return mParticipant->isReady();
}

void ParticipantController::observe(Game& game, int pIndex)
{
	mObserver.track(pIndex);
}

void ParticipantController::handleException(std::exception& exp)
{
	mObserver.handleException(exp);
}