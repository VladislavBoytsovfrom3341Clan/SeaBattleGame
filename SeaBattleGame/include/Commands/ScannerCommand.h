#ifndef SCANNER_COMMAND_H
#define SCANNER_COMMAND_H

#include "ICommand.h"
#include "Coords.h"

class ScannerCommand: public ICommand
{
	int mParticipantIndex;
	Coords mCoords;

public:
	ScannerCommand(int participantIndex, Coords coords);

	void execute(class Game& game) override;
};

#endif