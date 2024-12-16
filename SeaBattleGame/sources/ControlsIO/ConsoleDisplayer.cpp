#include "ConsoleDisplayer.h"


void ConsoleDisplayer::printShip(Battleship& ship)
{
	auto segments = ship.getShipCondition();
	std::cout << "Ship " << ship.getPosition().toString() << " condition:\n\t";
	for (auto segment : segments)
		std::cout << int(segment) << ' ';
	std::cout << '\n';
}

void ConsoleDisplayer::printShipsInManager(ShipManager& manager)
{
	std::cout << "Inactive ships in manager: " << manager.getInactiveShipsNumber() << '\n';
	for (int i = 0; i < manager.getInactiveShipsNumber(); i++)
		printShip(manager.getInactiveShip(i));

	std::cout << "Active ships in manager: " << manager.getActiveShipsNumber() << '\n';
	for (int i = 0; i < manager.getActiveShipsNumber(); i++)
		printShip(manager.getActiveShip(i));
}

void ConsoleDisplayer::printAbilityManager(AbilityManager& aManager)
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

void ConsoleDisplayer::drawFriendField(Battlefield& field)
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

void ConsoleDisplayer::drawEnemyField(Battlefield& field)
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

void ConsoleDisplayer::display(GameInfo& gInfo, int pIndex)
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
