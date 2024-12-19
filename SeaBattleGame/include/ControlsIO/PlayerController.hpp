#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "ParticipantController.h"
#include "IGameDisplayer.h"
#include "Game.h"

#include "Player.h"
#include "CLIInput.h"

template <typename Input>
class PlayerController : public ParticipantController
{
	Input mInput;

public:

	PlayerController(Game& game, int index, IGameDisplayer* displayer);

	ICommand* getAction() override;
	
};

template<typename Input>
inline PlayerController<Input>::PlayerController(Game& game, int index, IGameDisplayer* displayer):
	ParticipantController(game, index)
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
