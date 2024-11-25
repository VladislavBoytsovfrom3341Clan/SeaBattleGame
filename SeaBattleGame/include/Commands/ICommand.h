#ifndef I_COMMAND_H
#define I_COMMAND_H


class ICommand
{
public:
	virtual void execute(class GameController& gameController) = 0;
};

#endif