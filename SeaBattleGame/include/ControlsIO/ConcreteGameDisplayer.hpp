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

	void displayAbilityResult(AbilityResult& result) override;

	void informNewRound() override;

	void informNewGame() override;

	void informError(const std::exception& exp) override;
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

template<typename Displayer>
inline void ConcreteGameDisplayer<Displayer>::displayAbilityResult(AbilityResult& result)
{
	if (result.getType() == AbilityType::Scanner)
		mDisplayer.printScannerResult(dynamic_cast<ScannerResult&>(result));
}

template<typename Displayer>
inline void ConcreteGameDisplayer<Displayer>::informNewRound()
{
	mDisplayer.printNewRound();
}


template<typename Displayer>
inline void ConcreteGameDisplayer<Displayer>::informNewGame()
{
	mDisplayer.printNewGame();
}

template<typename Displayer>
inline void ConcreteGameDisplayer<Displayer>::informError(const std::exception& exp)
{
	mDisplayer.printErrorMessage(exp.what());
}

#endif
