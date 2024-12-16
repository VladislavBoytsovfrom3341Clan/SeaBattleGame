#include "ParticipantController.h"

void ParticipantController::setParticipant(Participant* participant)
{
	mParticipant = participant;
}

bool ParticipantController::isReady()
{
	return mParticipant->isReady();
}

void ParticipantController::observe(GameInfo& gInfo, int pIndex)
{
	mObserver.track(gInfo, pIndex);
}