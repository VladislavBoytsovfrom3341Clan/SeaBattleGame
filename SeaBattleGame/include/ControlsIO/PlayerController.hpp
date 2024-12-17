#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "ParticipantController.h"
#include "IGameDisplayer.h"

#include "Player.h"
#include "CLIInput.h"

template <typename Input>
class PlayerController : public ParticipantController
{
	Input mInput;

public:

	PlayerController(IGameDisplayer* displayer);

	ICommand* getAction() override;
	
};

template<typename Input>
inline PlayerController<Input>::PlayerController(IGameDisplayer* displayer)
{
	mObserver.changeDisplayer(displayer);
	mInput.rebindKeysFromFile();
}

template<typename Input>
inline ICommand* PlayerController<Input>::getAction()
{
	return mInput.readCommand();
}

#endif
