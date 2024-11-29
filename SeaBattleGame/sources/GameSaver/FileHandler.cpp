#include "FileHandler.h"

#include "Battleship.h"
#include "Battlefield.h"

#include <stdexcept>
#include <iostream>

FileHandler::FileHandler(std::string name, bool writeMode)
{
	if (writeMode)
	{
		mOutFile.open(name);
		if (!(mOutFile.is_open()))
			throw std::runtime_error("error in opening Output stream");
	}
	else
	{
		mInFile.open(name);
		if (!(mInFile.is_open()))
			throw std::runtime_error("error in opening Input stream");
	}
}

void FileHandler::write(GameSaver& state)
{
	std::cout << "+handler\n";
	mOutFile << state;
}

void FileHandler::read(GameSaver& state)
{
	std::cout << "+handler\n";
	mInFile >> state;
}

FileHandler::~FileHandler()
{
	if (mInFile.is_open())
		mInFile.close(); 
	if (mOutFile.is_open())
		mOutFile.close();
}