#include "FileHandler.h"

#include "Battleship.h"
#include "Battlefield.h"

#include <stdexcept>
#include <iostream>

FileHandler::FileHandler(std::string name)
{
	mName = name;
}

void FileHandler::openRead()
{
	mInFile.open(mName);
	if (!(mInFile.is_open()))
		throw std::runtime_error("error in opening Input stream");
}

void FileHandler::openWrite()
{
	mOutFile.open(mName);
	if (!(mOutFile.is_open()))
		throw std::runtime_error("error in opening Output stream");
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

void FileHandler::closeRead()
{
	if (mInFile.is_open())
		mInFile.close();
}

void FileHandler::closeWrite()
{
	if (mOutFile.is_open())
		mOutFile.close();
}