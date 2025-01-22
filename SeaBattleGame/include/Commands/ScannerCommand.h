#ifndef SCANNER_COMMAND_H
#define SCANNER_COMMAND_H

#include "ICommand.h"
#include "Coords.h"

/*
* Orders to cast Scanner command
* to some participant
* with some coords
*/
class ScannerCommand: public ICommand
{
	//Participant on whom the scanner will be used
	int mParticipantIndex;

	//Coords of left-up corner of scanning area
	Coords mCoords;

public:
	ScannerCommand(int participantIndex, Coords coords);

	//Orders game to scan area
	void execute(class Game& game) override;
};

#endif