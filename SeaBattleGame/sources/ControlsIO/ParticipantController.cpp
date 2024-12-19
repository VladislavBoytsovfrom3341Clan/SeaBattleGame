#include "ParticipantController.h"

ParticipantController::ParticipantController(Game& game) :
	mObserver(game) {
}

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
	mObserver.track(pIndex);
}

void ParticipantController::handleException(std::exception& exp)
{
	mObserver.handleException(exp);
}