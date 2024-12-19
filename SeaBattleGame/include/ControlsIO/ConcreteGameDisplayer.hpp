#ifndef CONCRETE_GAME_DISPLAYER_H
#define CONCRETE_GAME_DISPLAYER_H

#include "IGameDisplayer.h"

#include "ScannerResult.h"

template<typename Displayer>
class ConcreteGameDisplayer : public IGameDisplayer
{
	Displayer mDisplayer;
public:

	void display(GameInfo& gInfo, int pIndex) override;

	void displayShipPositioning(GameInfo& gInfo, int pIndex) override;

	void displayAbilityResultResult(AbilityResult& result) override;
};

template<typename Displayer>
inline void ConcreteGameDisplayer<Displayer>::display(GameInfo& gInfo, int pIndex)
{
	mDisplayer.display(gInfo, pIndex);
}

template<typename Displayer>
inline void ConcreteGameDisplayer<Displayer>::displayShipPositioning(GameInfo& gInfo, int pIndex)
{
	mDisplayer.printShipsInManager(gInfo.mParticipants[pIndex]->mShipManager);
	mDisplayer.drawFriendField(gInfo.mParticipants[pIndex]->mField);
}

#include<iostream>

template<typename Displayer>
inline void ConcreteGameDisplayer<Displayer>::displayAbilityResultResult(AbilityResult& result)
{
	if (result.getType() == AbilityType::Scanner)
		mDisplayer.printScannerResult(dynamic_cast<ScannerResult&>(result));
}
#endif
