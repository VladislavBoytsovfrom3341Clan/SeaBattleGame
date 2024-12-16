#ifndef CONCRETE_GAME_DISPLAYER_H
#define CONCRETE_GAME_DISPLAYER_H

#include "IGameDisplayer.h"

template<typename Displayer>
class ConcreteGameDisplayer : public IGameDisplayer
{
	Displayer mDisplayer;
public:

	void display(GameInfo& gInfo, int pIndex) override;
};

template<typename Displayer>
inline void ConcreteGameDisplayer<Displayer>::display(GameInfo& gInfo, int pIndex)
{
	mDisplayer.display(gInfo, pIndex);
}

#endif
