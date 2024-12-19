#include "ParticipantController.h"

void ParticipantController::setParticipant(Participant* participant)
{
	mParticipant = participant;
}

bool ParticipantController::isReady()
{
	return mParticipant->isReady();
}

void ParticipantController::observe(Game& game, int pIndex)
{
	mObserver.track(game, pIndex);
}

void ParticipantController::handleException(std::exception& exp)
{
	mObserver.handleException(exp);
}