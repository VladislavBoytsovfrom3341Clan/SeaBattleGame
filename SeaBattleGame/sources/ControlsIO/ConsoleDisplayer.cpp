#include "ConsoleDisplayer.h"


void ConsoleDisplayer::printShip(const Battleship& ship) const
{
	auto segments = ship.getShipCondition();
	std::cout << "Ship " << ship.getPosition().toString() << " condition:\n\t";
	for (auto segment : segments)
		std::cout << int(segment) << ' ';
	std::cout << '\n';
}

void ConsoleDisplayer::printShipsInManager(const ShipManager& manager) const
{
	std::cout << "Inactive ships in manager: " << manager.getInactiveShipsNumber() << '\n';
	for (int i = 0; i < manager.getInactiveShipsNumber(); i++)
		printShip(manager.getInactiveShip(i));

	std::cout << "Active ships in manager: " << manager.getActiveShipsNumber() << '\n';
	for (int i = 0; i < manager.getActiveShipsNumber(); i++)
		printShip(manager.getActiveShip(i));
}

void ConsoleDisplayer::printAbilityManager(const AbilityManager& aManager) const
{
	switch (aManager.getFirstAbility())
	{
	case AbilityType::DoubleDamage:
		std::cout << "DoubleDamage\n";
		break;
	case AbilityType::Scanner:
		std::cout << "Scanner\n";
		break;
	case AbilityType::Shelling:
		std::cout << "Shelling\n";
	}
}

void ConsoleDisplayer::drawFriendField(const Battlefield& field) const
{
	std::cout << "\n";
	Coords fieldSize = field.size();
	for (int y = 0; y < fieldSize.y; y++)
	{
		for (int x = 0; x < fieldSize.x; x++)
		{
			CellStatus status = field.getCellStatus({ x, y });
			if (status == CellStatus::unknown)
			{
				if (field.hasShipAtCell({ x, y }) == false)
					std::cout << ".";
				else
				{
					SegmentCondition condition = field.getCellShipCondition({ x, y });
					if (condition == SegmentCondition::intact)
						std::cout << '0';
					else if (condition == SegmentCondition::damaged)
						std::cout << "x";
					else
						std::cout << "X";
				}
			}
			else if (status == CellStatus::empty)
				std::cout << "*";
			else if (status == CellStatus::shipped)
			{
				SegmentCondition condition = field.getCellShipCondition({ x, y });
				if (field.hasShipAtCell({ x, y }) == false || condition == SegmentCondition::intact)
					std::cout << "0";
				else if (condition == SegmentCondition::damaged)
					std::cout << "x";
				else
					std::cout << "X";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void ConsoleDisplayer::drawEnemyField(const Battlefield& field) const
{
	std::cout << "\n";
	Coords fieldSize = field.size();
	for (int y = 0; y < fieldSize.y; y++)
	{
		for (int x = 0; x < fieldSize.x; x++)
		{
			CellStatus status = field.getCellStatus({ x, y });
			if (status == CellStatus::unknown)
				std::cout << "-";
			else if (status == CellStatus::empty)
				std::cout << "*";
			else if (status == CellStatus::shipped)
			{
				SegmentCondition condition = field.getCellShipCondition({ x, y });
				if (field.hasShipAtCell({ x, y }) == false || condition == SegmentCondition::intact)
					std::cout << "0";
				else if (condition == SegmentCondition::damaged)
					std::cout << "x";
				else
					std::cout << "X";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void ConsoleDisplayer::display(const GameInfo& gInfo, int pIndex) const
{
	std::cout << "\nMove " << gInfo.mMoveIndex << '\n';
	for (int i = 0; i < gInfo.mParticipantsNumber; i++)
	{
		if (i == pIndex)
		{
			std::cout << "This is you! #" << i << '\n';
			if (!(gInfo.mParticipants[i]->mAbilityManager.empty()))
				printAbilityManager(gInfo.mParticipants[i]->mAbilityManager);
			printShipsInManager(gInfo.mParticipants[i]->mShipManager);
			drawFriendField(gInfo.mParticipants[i]->mField);
		}
		else
		{
			std::cout << "Enemy #" << i << '\n';
			if (!(gInfo.mParticipants[i]->mAbilityManager.empty()))
				printAbilityManager(gInfo.mParticipants[i]->mAbilityManager);
			printShipsInManager(gInfo.mParticipants[i]->mShipManager);
			drawEnemyField(gInfo.mParticipants[i]->mField);
		}
	}
}

void ConsoleDisplayer::printScannerResult(const ScannerResult& scRes) const
{
	std::cout << "\nScanner found " << scRes.getResult() << " ship segments in the area!\n";
}

void ConsoleDisplayer::printNewRound() const
{
	std::cout << "\n\nNew round has started!\n\n";
}

void ConsoleDisplayer::printNewGame() const
{
	std::cout << "\n\n\nNew Game has started!\n\n\n";
}

void ConsoleDisplayer::printErrorMessage(const char* str) const
{
	std::cout << "\nAn impossible action was tried to be made:\n" << str << '\n';
}